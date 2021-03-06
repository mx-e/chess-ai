from invoke import task


@task
def build(c, python="python"):

    print("\033[0;92m[PRE-BUILD]: test chesscpp")
    c.run("cd chesscpp && invoke test --remake", pty=True)

    print("\033[0;92m[BUILD]: Chess-AI module\033[0;37m")
    c.run(
        f"CHESSAI_VERSION=hash+aspiration {python}  -m pip install . --force-reinstall",
        pty=True,
    )

    print("\033[0;92m[POST-BUILD]: discover python tests\033[0;37m")
    c.run(f"{python} -m unittest discover .", pty=True)
