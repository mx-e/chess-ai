#include "types.hpp"
#include <memory>
#include <map>

class Piece
{
public:
    Piece(int color);

    /**
     * @brief Provides the immediate directions a piece can move, given the current position.
     * Note that the method should return also directions that are invalid given the
     * game state or board limits. In a sense, this method returns all conceivable moves.
     * @param position
     * @return Directions
     */
    virtual Directions get_directions(Position position) = 0;

    virtual int get_steps() = 0;

    virtual int get_id() = 0;

    virtual int get_color();

protected:
    int color;
};

typedef std::map<int, std::shared_ptr<Piece> > AvailablePieces;

class Pawn : public Piece
{
    using Piece::Piece;

    virtual Directions get_directions(Position position);

    virtual int get_steps();

    virtual int get_id();
};

class King : public Piece
{
    using Piece::Piece;

    virtual Directions get_directions(Position position);

    virtual int get_steps();

    virtual int get_id();
};

class Queen : public Piece
{
    using Piece::Piece;

    virtual Directions get_directions(Position position);

    virtual int get_steps();

    virtual int get_id();
};

class Bishop : public Piece
{
    using Piece::Piece;

    virtual Directions get_directions(Position position);

    virtual int get_steps();

    virtual int get_id();
};

class Knight : public Piece
{
    using Piece::Piece;

    virtual Directions get_directions(Position position);

    virtual int get_steps();

    virtual int get_id();
};

class Rook : public Piece
{
public:
    using Piece::Piece;

    virtual Directions get_directions(Position position);

    virtual int get_steps();

    virtual int get_id();
};