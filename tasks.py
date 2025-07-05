"""
Tasks to run through invoke
"""

from invoke import task, context

# The Sort Methods that can be called:
sort_methods = ['bubble', 'heap', 'merge', 'quick', 'tree']

@task()
def clean(cmd: context.Context) -> None:
    """Cleans artifacts from the project. Can be called with `invoke clean`.
    Args:
        cmd (context.Context): Context invoke passes to run commands
    Returns:
        None
    """
    cmd.run('rm -rf bin')


@task(clean)
def build(cmd: context.Context) -> None:
    """Builds the project. Can be called with `invoke build`.
    Args:
        cmd (context.Context): Context invoke passes to run commands
    Returns:
        None
    """
    # Build the libraries and test binaries
    cmd.run('mkdir bin build;cmake -B build -S .;cd build;make')
    # Move the test binaries to the project directory
    test_loc = 'build/tests/'
    for sort_method in sort_methods:
        cmd.run(f"cp {test_loc}{sort_method}_test bin/")

@task(build, help={'sort_type': 'Name of the sorting method to use. Use `all` to run each'})
def test(cmd: context.Context, sort_type: str) -> None:
    """Runs and tests the algorithms. Can be called with `invoke test <sort_type>`.
    For example, using `invoke test all` runs each, while
    `invoke test bubble` only runs bubble sort.
    Args:
        cmd (context.Context): Context invoke passes to run commands
        sort_type (str): The sorting method to test, or `all`
    Returns:
        None
    """
    sort_lower = sort_type.lower()
    if sort_lower == 'all':
        for sort_method in sort_methods:
            cmd.run(f"./bin/src/{sort_method}")
    elif sort_lower in sort_methods:
        cmd.run(f"./bin/{sort_lower}_test")
    else:
        print(f"Sort Type '{sort_type}' is not implemented")
