#!/usr/bin/python3
"""Determine if a given sequence of integers represents valid UTF-8 data."""
# pylint: disable=invalid-name


def validUTF8(data: list) -> bool:
    """
    Check if a sequence of integers represents a valid UTF-8 encoding.
    Arguments:
        data (List[int]): the sequence of integers to check
    Return:
        True if data represents a valid UTF-8 encoding, False otherwise
    """
    try:
        bytes(x & 0xff for x in data).decode()
        return True
    except UnicodeDecodeError:
        return False
