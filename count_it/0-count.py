import praw

def count_words(subreddit, word_list, reddit=None, results=None):
    if reddit is None:
        reddit = praw.Reddit(client_id='YOUR_CLIENT_ID',
                             client_secret='YOUR_CLIENT_SECRET',
                             user_agent='YOUR_USER_AGENT')

    if results is None:
        results = {}

    try:
        subreddit = reddit.subreddit(subreddit)
        hot_articles = subreddit.hot(limit=10)

        for submission in hot_articles:
            title = submission.title.lower()
            for word in word_list:
                word = word.lower()
                if word in title:
                    results[word] = results.get(word, 0) + title.count(word)

        count_words(subreddit, word_list, reddit, results)

    except Exception as e:
        print("Error:", e)

    if not results:
        return

    sorted_results = sorted(results.items(), key=lambda x: (-x[1], x[0]))

    for word, count in sorted_results:
        print(f"{word}: {count}")
