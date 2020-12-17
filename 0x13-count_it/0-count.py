#!/usr/bin/python3
"""
Show number of occurrences of keywords in hot post titles (case-insensitive)
"""
from collections import Counter, defaultdict
import requests

URL_TEMPLATE = 'https://www.reddit.com/r/{}/hot.json'


def count_words(subreddit, wordlist, count=None, after=None):
    """
    Query reddit for hot posts and print total occurrences of each keyword
    """
    response = requests.get(
            URL_TEMPLATE.format(subreddit),
            headers={'User-Agent': 'Mozilla/5.0'},
            params={'after': after, 'limit': 100},
            allow_redirects=False,
        )
    if response.status_code == 200:
        if count is None:
            count = defaultdict(int)
        data = response.json().get('data')
        page = Counter(
            word for article in data.get('children')
            for word in article.get('data').get('title').casefold().split()
        )
        for word in wordlist:
            if word.casefold() in page:
                count[word.casefold()] += page.get(word.casefold())
        if data.get('after') is None:
            by_key = sorted(count.items(), key=lambda x: x[0])
            for key, value in sorted(by_key, key=lambda x: x[1], reverse=True):
                print('{}: {}'.format(key, value))
        else:
            count_words(subreddit, wordlist, count, data.get('after'))
