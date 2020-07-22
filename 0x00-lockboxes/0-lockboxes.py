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
    locked = set(range(len(boxes)))
    opened = {0}
    while locked and opened:
        locked -= opened
        opened = {key for box in opened for key in boxes[box] if key in locked}
    return not locked
