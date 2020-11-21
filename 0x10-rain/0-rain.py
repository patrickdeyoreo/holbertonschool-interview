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
            lower = walls[lhs]
            lhs += 1
        else:
            lower = walls[rhs]
            rhs -= 1
        if level < lower:
            level = lower
        water += level - lower
    return water
