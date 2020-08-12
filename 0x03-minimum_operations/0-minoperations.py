#!/usr/bin/python3
"""
Provide a function to compute the minimum numper of copy-paste operations
to produce a given number of characters.
"""
# pylint: disable=invalid-name


def sieve_of_eratosthenes(n):
    """Compute the set of all primes up to n."""
    primes = set(range(2, n + 1))
    for i in range(2, int(n ** 0.5) + 1):
        if i in primes:
            for j in (i ** 2 + i * m for m in range(n + 1)):
                if j > n:
                    break
                primes.discard(j)
    return primes


def minOperations(n):
    """Calculate the minimum number of operations to produce n characters."""
    # primes = sieve_of_eratosthenes(n)
    ops = 0
    while n > 1:
        for prime in range(2, n + 1):
            if n % prime == 0:
                ops += prime
                n //= prime
                break
    return ops
