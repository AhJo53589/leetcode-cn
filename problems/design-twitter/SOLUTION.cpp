
//////////////////////////////////////////////////////////////////////////
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

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

//////////////////////////////////////////////////////////////////////////
//int _solution_run(int)
//{
//}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{
    vector<string> sf = tc.get<vector<string>>();
    vector<string> sp = tc.get<vector<string>>();
    vector<string> ans;

    Twitter *obj = nullptr;
    for (auto i = 0; i < sf.size(); i++)
    {
        if (sf[i] == "Twitter")
        {
            obj = new Twitter();
            ans.push_back("null");
        }
        else if (sf[i] == "postTweet")
        {
            TestCases stc(sp[i]);
            int userId = stc.get<int>();
            int tweetId = stc.get<int>();
            obj->postTweet(userId, tweetId);
            ans.push_back("null");
        }
        else if (sf[i] == "getNewsFeed")
        {
            TestCases stc(sp[i]);
            int userId = stc.get<int>();
            vector<int> r = obj->getNewsFeed(userId);
            ans.push_back(convert<string>(r));
        }
        else if (sf[i] == "follow")
        {
            TestCases stc(sp[i]);
            int followerId = stc.get<int>();
            int followeeId = stc.get<int>();
            obj->follow(followerId, followeeId);
            ans.push_back("null");
        }
        else if (sf[i] == "unfollow")
        {
            TestCases stc(sp[i]);
            int followerId = stc.get<int>();
            int followeeId = stc.get<int>();
            obj->unfollow(followerId, followeeId);
            ans.push_back("null");
        }
    }
    delete obj;

    return convert<string>(ans);
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
