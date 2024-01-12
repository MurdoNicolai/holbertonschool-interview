#!/usr/bin/python3
"""
contains count words frome reddit
"""
import requests

def count_words(subreddit, word_list, count = 100):
    if count == 0:
        return 1
    count_words(subreddit, word_list, count  - 1)
# def authenticate():
#     client_id = "Ug5rrdH_0onrKkRtb5ZGkg"
#     client_secret = "N6-MUrHe2IggUlB8PfUFbetnZIpr9A"
#     username = "odrumteadrinker"
#     password = "12ty45er78az"
#     auth_url = "https://www.reddit.com/api/v1/access_token"
#     auth_payload = {
#         "grant_type": "password",
#         "username": username,
#         "password": password
#     }
#     auth_headers = {
#         "User-Agent": "YOUR_USER_AGENT"
#     }

#     response = requests.post(auth_url, data=auth_payload, headers=auth_headers, auth=(client_id, client_secret))

#     if response.status_code == 200:
#         return response.json().get("access_token")
#     else:
#         raise Exception(f"Authentication failed: {response.text}")

# def count_words(subreddit, word_list, after=None, results=None):
#     if results is None:
#         results = {}

#     try:
#         access_token = authenticate()

#         url = f"https://oauth.reddit.com/r/{subreddit}/hot"
#         params = {'limit': 10, 'after': after} if after else {'limit': 10}
#         headers = {
#             'Authorization': f'Bearer {access_token}',
#             'User-Agent': 'YOUR_USER_AGENT'
#         }

#         response = requests.get(url, params=params, headers=headers)
#         response.raise_for_status()

#         data = response.json()
#         after = data['data']['after']
#         submissions = data['data']['children']

#         # for submission in submissions:
#         #     title = submission['data']['title'].lower()
#         #     for word in word_list:
#         #         word = word.lower()
#         #         if word in title:
#         #             results[word] = results.get(word, 0) + title.count(word)

#         if after is None:
#             sorted_results = sorted(results.items(), key=lambda x: (-x[1], x[0]))
#             # for word, count in sorted_results:
#             #     print(f"{word}: {count}")
#             return results

#         return count_words(subreddit, word_list, after, results)

#     except requests.exceptions.RequestException as e:
#         print("Error:", e)
#         return results
