# `（中等）` [355.design-twitter 设计推特](https://leetcode-cn.com/problems/design-twitter/)

### 题目描述
<p>设计一个简化版的推特(Twitter)，可以让用户实现发送推文，关注/取消关注其他用户，能够看见关注人（包括自己）的最近十条推文。你的设计需要支持以下的几个功能：</p>

<ol>
	<li><strong>postTweet(userId, tweetId)</strong>: 创建一条新的推文</li>
	<li><strong>getNewsFeed(userId)</strong>: 检索最近的十条推文。每个推文都必须是由此用户关注的人或者是用户自己发出的。推文必须按照时间顺序由最近的开始排序。</li>
	<li><strong>follow(followerId, followeeId)</strong>: 关注一个用户</li>
	<li><strong>unfollow(followerId, followeeId)</strong>: 取消关注一个用户</li>
</ol>

<p><strong>示例:</strong></p>

<pre>Twitter twitter = new Twitter();

// 用户1发送了一条新推文 (用户id = 1, 推文id = 5).
twitter.postTweet(1, 5);

// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
twitter.getNewsFeed(1);

// 用户1关注了用户2.
twitter.follow(1, 2);

// 用户2发送了一个新推文 (推文id = 6).
twitter.postTweet(2, 6);

// 用户1的获取推文应当返回一个列表，其中包含两个推文，id分别为 -&gt; [6, 5].
// 推文id6应当在推文id5之前，因为它是在5之后发送的.
twitter.getNewsFeed(1);

// 用户1取消关注了用户2.
twitter.unfollow(1, 2);

// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
// 因为用户1已经不再关注用户2.
twitter.getNewsFeed(1);
</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/design-twitter/solution/design-twitter-by-ikaruga/)

### 答题
``` C++
class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweetList[userId].insert(tweetDic.size());
        tweetDic.push_back(tweetId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        if (followList[userId].count(userId) == 0)
        {
            follow(userId, userId);
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto f : followList[userId])
        {
            for (auto a : tweetList[f])
            {
                if (pq.size() == 10 && a < pq.top()) continue;
                pq.push(a);
                if (pq.size() <= 10) continue;
                pq.pop();
            }
        }

        vector<int> ans;
        while (!pq.empty())
        {
            ans.push_back(tweetDic[pq.top()]);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        followList[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followList[followerId].count(followeeId) != 0)
        {
            followList[followerId].erase(followeeId);
        }
    }

private:
    unordered_map<int, unordered_set<int>> followList;
    unordered_map<int, set<int>> tweetList;
    vector<int> tweetDic;
};
```




