#!/usr/bin/python3
"""
Maria and Ben are playing a game. Given a set of consecutive integers starting
from 1 up to and including n, they take turns choosing a prime number from the
set and removing that number and its multiples from the set. The player that
cannot make a move loses the game.
"""

def isWinner(x, nums):
    """
    Play the prime game.
    Arguments:
        x: number of rounds
        nums: sequence of n consecutive integers starting at 1
    Description:
        It's Maria vs. Ben.
        Maria always goes first.
        Both players play optimally.
    Return:
        If the winner cannot be determined, return None. Otherwise, return the
        name of the player that won the most rounds.
    """
    if x < 1:
        return None

    nums = list(nums)
    if len(nums) < 1:
        return None

    n = max(nums)
    if n < 1:
        return None

    sieve = [True for _ in range(n + 1)]
    sieve[0] = False
    sieve[1] = False
    for i in range(2, int(n ** 0.5) + 1):
        if sieve[i]:
            for j in range(i * i, n + 1, i):
                sieve[j] = False

    prime_count = [0 for _ in range(len(nums))]
    for i in range(len(nums)):
        count = 0
        for j in range(nums[i] + 1):
            if (sieve[j]):
                count += 1
        prime_count[i] = count

    score = 0
    for num in prime_count:
        if num % 2 == 0:
            score += 1
    if 2 * score > x:
        return "Ben"
    if 2 * score < x:
        return "Maria"
    return None
