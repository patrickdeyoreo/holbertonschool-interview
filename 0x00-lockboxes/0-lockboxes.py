#!/usr/bin/python3
"""
Given a list of locked boxes each of which may contain keys to other boxes,
determine if a key to the first box is sufficient to unlock all the others.
"""


def canUnlockAll(boxes):
    """
    Determine if the boxes can be unlocked given only a key to the first.
    Arguments:
        boxes: each box contains the indices of the boxes it unlocks
    Return:
        True if the boxes can be unlocked; False otherwise.
    """
    locked = {*range(len(boxes))}
    unlock = {0}
    while locked and unlock:
        unlock &= locked
        locked -= unlock
        unlock = {key for box in unlock for key in boxes[box]}
    return not locked
