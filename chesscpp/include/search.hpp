#ifndef SEARCH
#define SEARCH

#include "types.hpp"
#include "evaluations.hpp"
#include "transforms.hpp"

void print_optimal_move_sequence(MoveList &move_list)
{
    for (move m : move_list)
    {
        printf("%s -> ", move_to_uci_str(m).c_str());
    }

    printf("\n");
}

void print_optimal_line(C_Session &session, Line &line)
{
    for (int i = 0; i < session.alpha_beta_state.current_max_depth; i++)
    {
        printf("%s -> ", move_to_uci_str(line.argmove[i]).c_str());
    }
    std::cout << "\n";
}

float q_search_dummy(C_Session &session, float alpha, float beta, int depth)
{
    if (session.board_state.king_attack || session.board_state.castling_move_illegal)
        return high_value;
    return evaluate(session.board_state);
}

float quiescence_search(C_Session &session, float alpha, float beta, int depth)
{
    if (session.board_state.king_attack || session.board_state.castling_move_illegal)
        return high_value;
    float current_score = evaluate(session.board_state);
    if (depth >= max_quiesence_depth)
        return current_score;
    if (current_score >= beta)
        return beta;
    if (alpha < current_score)
        alpha = current_score;
    MoveList &move_list = session.move_list_stack[depth];
    for (move m : move_list)
    {
        if (m.capture == 0)
            continue;
        ++session.alpha_beta_state.nodes_at_depth[session.alpha_beta_state.current_max_depth];
        push_move(session.board_state, m, session.move_list_stack[depth + 1]);
        float score = -quiescence_search(session, -beta, -alpha, depth + 1);
        pop_move(session.board_state);
        session.move_list_stack[depth + 1].clear();

        if (score >= beta)
            return beta;
        if (score > alpha)
            alpha = score;
    }
    return alpha;
}

float zw_search(C_Session &session, float beta, int depth_left)
{
    int depth = session.alpha_beta_state.current_max_depth - depth_left;
    if (session.board_state.king_attack || session.board_state.castling_move_illegal)
        return high_value;
    if (depth_left == 0)
        return quiescence_search(session, beta - 1, beta, depth);

    MoveList &move_list = session.move_list_stack[depth];

    for (move m : move_list)
    {
        ++session.alpha_beta_state.nodes_at_depth[session.alpha_beta_state.current_max_depth];
        push_move(session.board_state, m, session.move_list_stack[depth + 1]);

        float score = -zw_search(session, 1 - beta, depth_left - 1);

        pop_move(session.board_state);
        session.move_list_stack[depth + 1].clear();

        if (score >= beta)
            return beta;
    }

    return beta - 1;
}

bool check_check_mate(C_Session &session, int depth)
{
    uint8_t king_field = scan_board(get_king(session.board_state, session.board_state.turn)).front();
    move king_non_move = create_move(king_field, king_field);
    push_move(session.board_state, king_non_move, session.move_list_stack[depth + 1]);
    bool is_check_mate = session.board_state.king_attack;
    pop_move(session.board_state);
    session.move_list_stack[depth + 1].clear();
    return is_check_mate;
}

float pv_search(C_Session &session, float alpha, float beta, int depth_left, Line &pline)
{
    Line line;
    int depth = session.alpha_beta_state.current_max_depth - depth_left;
    if (session.board_state.king_attack || session.board_state.castling_move_illegal)
        return high_value;
    if (depth_left == 0)
    {
        pline.n_moves = 0;
        return quiescence_search(session, alpha, beta, depth);
    }

    MoveList &move_list = session.move_list_stack[depth];

    bool search_pv = alpha == -infty;
    float score;

    for (move m : move_list)
    {
        ++session.alpha_beta_state.nodes_at_depth[session.alpha_beta_state.current_max_depth];
        push_move(session.board_state, m, session.move_list_stack[depth + 1]);

        if (search_pv)
        {
            score = -pv_search(session, -beta, -alpha, depth_left - 1, line);
        }
        else
        {
            score = -zw_search(session, -alpha, depth_left - 1);
            if (score > alpha)
                score = -pv_search(session, -beta, -alpha, depth_left - 1, line);
        }
        pop_move(session.board_state);
        session.move_list_stack[depth + 1].clear();

        if (score >= beta)
            return beta;

        if (score > alpha)
        {
            pline.argmove[0] = m;
            ::memcpy(pline.argmove + 1, line.argmove, line.n_moves * sizeof(move));
            pline.n_moves = line.n_moves + 1;
            alpha = score;
            search_pv = false;
        }
    }
    return alpha;
}

template <class T>
inline bool exists_(std::vector<T> iterable, std::function<bool(T)> condition)
{
    bool found;
    for (auto item : iterable)
    {
        found = found || condition(item);
    }
    return found;
}

void undo_all_moves(C_Session &session)
{
    int depth = session.board_state.move_stack.size();
    for (int i = 0; i < depth; i++)
    {
        session.move_list_stack[i + 1].clear();
    }
    while (session.board_state.move_stack.size() > 0)
    {
        pop_move(session.board_state);
    }
}

inline int alphabeta(C_Session &session, int max_depth)
{
    Line line;
    int window_idx = 0;
    collect_legal_moves(session.board_state, session.move_list_stack[0]);

    float best_move_score;
    while (true)
    {
        best_move_score = pv_search(session, session.alpha_beta_state.current_alpha, session.alpha_beta_state.current_beta, max_depth, line);
        if ((best_move_score <= session.alpha_beta_state.current_alpha) || (best_move_score >= session.alpha_beta_state.current_beta))
        {
            ++window_idx;
            if (window_idx >= max_n_fallbacks)
            {
                session.alpha_beta_state.current_alpha = -infty;
                session.alpha_beta_state.current_beta = infty;
            }
            else
            {
                session.alpha_beta_state.current_alpha -= alpha_aspirations[window_idx];
                session.alpha_beta_state.current_beta += alpha_aspirations[window_idx];
            }
        }
        else
        {
            break;
        }
    }
    session.alpha_beta_state.current_alpha = best_move_score - alpha_aspirations[window_idx];
    session.alpha_beta_state.current_beta = best_move_score + alpha_aspirations[window_idx];

    ::memcpy(session.alpha_beta_state.current_best_line.argmove, line.argmove, max_depth * sizeof(move));
    session.move_list_stack[0].clear();
    session.alpha_beta_state.bestmove = session.alpha_beta_state.current_best_line.argmove[0];

    return best_move_score;
}

#endif