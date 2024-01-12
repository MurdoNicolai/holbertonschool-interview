#!/usr/bin/python3
"""
contains count words frome reddit
"""
import requests

def count_words(subreddit, word_list, results=None, after=None):
    """
    counts givven word occurrences from subreddit in all hot articals
    """
    print(results)
    if results is None:
        results = {}

    try:
        url = f"https://www.reddit.com/r/{subreddit}/hot.json"
        params = {'after': after} if after else {}
        headers = {'User-Agent': 'YOUR_USER_AGENT'}

        response = requests.get(url, params=params, headers=headers)
        response.raise_for_status()

        data = response.json()
        after = data['data']['after']
        submissions = data['data']['children']

        for submission in submissions:
            title = submission['data']['title'].lower()
            for word in word_list:
                word = word.lower()
                if word in title:
                    results[word] = results.get(word, 0) + title.count(word)

        count_words(subreddit, word_list, results, after)

    except requests.exceptions.RequestException as e:
        print("Error:", e)

    if not results:
        return

    sorted_results = sorted(results.items(), key=lambda x: (-x[1], x[0]))

    for word, count in sorted_results:
        print(f"{word}: {count}")
