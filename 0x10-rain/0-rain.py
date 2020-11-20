#!/usr/bin/python3
"""see https://leetcode.com/problems/trapping-rain-water"""


def rain(walls: list) -> int:
    """Calculate how much rain water will be trapped when it rains."""
    lhs = 0
    rhs = len(walls) - 1
    level = 0
    water = 0
    while lhs < rhs:
        if walls[lhs] < walls[rhs]:
            low = walls[lhs]
            lhs += 1
        else:
            low = walls[rhs]
            rhs -= 1
        if low > level:
            level = low
        water += level - low
    return water
