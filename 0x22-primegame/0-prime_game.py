#!/usr/bin/python3
"""Play the prime game."""


def get_sieve(n):
    """Compute a sieve of eratosthenes."""
    sieve = [True for _ in range(n + 1)]
    sieve[0] = False
    sieve[1] = False
    for i in range(2, int(n ** 0.5) + 1):
        if sieve[i]:
            for j in range(i * i, n + 1, i):
                sieve[j] = False
    return sieve


def isWinner(x, nums):
    """Determine the winner of the prime game."""
    if x < 1:
        return None

    nums = list(nums)
    if len(nums) < 1:
        return None

    n = max(nums)
    if n < 1:
        return None

    sieve = get_sieve(n)

    prime_counts = [0 for _ in range(len(nums))]
    for i in range(len(nums)):
        count = 0
        for j in range(nums[i] + 1):
            if (sieve[j]):
                count += 1
        prime_counts[i] = count

    score = 0
    for count in prime_counts:
        if count % 2 == 0:
            score += 1
    if x > 2 * score:
        return "Maria"
    if x < 2 * score:
        return "Ben"
    return None
