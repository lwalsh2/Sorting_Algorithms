"""
Tasks to run through invoke
"""

from invoke import task, context


@task()
def clean(cmd: context.Context) -> None:
    """Cleans artifacts from the project. Can be called with `invoke clean`.
    Args:
        cmd (context.Context): Context invoke passes to run commands
    Returns:
        None
    """
    cmd.run("rm -rf bin")


@task(clean)
def build(cmd: context.Context) -> None:
    """Builds the project. Can be called with `invoke build`.
    Args:
        cmd (context.Context): Context invoke passes to run commands
    Returns:
        None
    """
    cmd.run("mkdir bin")
    cmd.run("cmake -B bin -S .")
    cmd.run("cd bin; make")

