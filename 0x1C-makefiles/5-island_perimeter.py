#!/usr/bin/python3
"""Defines the island_perimeter function."""


def island_perimeter(grid):
    """
    Calculate the perimeter of the island described in a grid.

    Args:
    - grid (matrix of int): The grid representing the island,
        where 1 represents land and 0 represents water.

    Returns:
    - int: The perimeter of the island.

    Example:

    >>> grid = [
        [0, 0, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 1, 1, 0, 0],
        [0, 0, 0, 0, 0, 0]
    ]
    island_perimeter(grid)

    ### Output: 12
    """
    if not grid:
        return 0

    perimeter = 0
    rows = len(grid)
    cols = len(grid[0])

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                perimeter += 4
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2

    return perimeter
