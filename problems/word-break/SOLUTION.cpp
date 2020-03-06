//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
    bool dfs(string& s, int i, vector<string>& wordDict)
    {
        if (i == s.size()) return true;

        for (auto& word : wordDict)
        {
            if (s.size() - i < word.size()) continue;
            if (memcmp(&s[i], &word[0], word.size()) == 0)
            {
                if (dfs(s, i + word.size(), wordDict)) return true;
            }
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict)
    {
        vector<string> newDict;
        sort(wordDict.begin(), wordDict.end());
        for (auto& word : wordDict)
        {
            if (dfs(word, 0, newDict)) continue;
            newDict.push_back(word);
        }
        return dfs(s, 0, newDict);
    }
};

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        size_t validEnd = 0;
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (i == validEnd + 1) return false;
            if (!dp[i]) continue;
            for (auto& word : wordDict)
            {
                size_t newEnd = i + word.size();
                if (newEnd > s.size()) continue;
                if (memcmp(&s[i], &word[0], word.size()) == 0)
                {
                    dp[newEnd] = true;
                    validEnd = max(validEnd, newEnd);
                }
            }
        }
        return dp.back();
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string s, vector<string>& wordDict)
{
    int caseNo = 5;
    static int caseCnt = 0;
    if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution2 sln;
    return sln.wordBreak(s, wordDict);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//    return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
