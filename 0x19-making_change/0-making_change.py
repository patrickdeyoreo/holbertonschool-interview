#!/usr/bin/python3
"""
Given a list of coin denominations, determine the fewest number of coins needed
to make a given amount.
"""


def makeChange(coins, total):
    """
    Determine the fewest number of coins needed to make a given amount.
    Arguments:
        coins: list of coin denominations
        total: total amount to make
    Return:
        If the amount cannot be produced by the given denominations, return -1.
        Otherwise return the fewest number of coins needed to make the amount.
    """
    if total > 0:
        level = [0]
        queue = []
        n_coins = 0
        checked = [True]
        checked.extend(False for _ in range(total))
        while level:
            n_coins += 1
            for value in level:
                for coin in coins:
                    if value + coin == total:
                        return n_coins
                    if value + coin >= total:
                        continue
                    if not checked[value + coin]:
                        checked[value + coin] = True
                        queue.append(value + coin)
            level = queue.copy()
            queue.clear()
        return -1
    return 0
