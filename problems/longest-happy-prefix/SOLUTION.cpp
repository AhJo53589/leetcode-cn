
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string longestPrefix(string s) 
    {
        int ans = 0;
        queue<int> que;
        queue<int> queFront;
        bool sameflag = true;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (i != 0 && s[0] == s[i])
            {
                queFront.push(i);
            }
            if (s[i] != s.back())
            {
                sameflag = false;
                continue;
            }
            que.push(i);
        }
        if (sameflag) return s.substr(0, s.size() - 1);

        while (!queFront.empty())
        {
            int same_len = s.size() - queFront.front();
            queFront.pop();

            while (!que.empty())
            {
                auto q = que.front();
                if (q - same_len <= 0) continue;
                if (memcmp(&s[0], &s[q - same_len], same_len))
                {
                    ans = max(ans, same_len);
                }
            }
            if (ans != 0) break;
        }
        return s.substr(0, ans);
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string s)
{
    int caseNo = -1;
    static int caseCnt = 0;
    if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.longestPrefix(s);
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
