
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int longestValidParentheses(string s)
    {
        pair<char, char> k = { '(',')' };
        s.insert(s.begin(), k.second);
        s.insert(s.begin(), k.second);
        vector<int> dp(s.size(), 0);
        int ans = 0;
        for (int i = 2; i < s.size(); i++)
        {
            if (s[i] == k.first)
            {
                dp[i] = 0;
            }
            else
            {
                if (s[i - 1] == k.first)
                {
                    dp[i] = dp[i - 2] + 2;
                }
                else if (s[i - dp[i - 1] - 1] == k.first)
                {
                    dp[i] = dp[i - dp[i - 1] - 2] + 2 + dp[i - 1];
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
    int longestValidParentheses(string s) 
    {
        pair<char, char> k = { '(',')' };
        map<char, int> dic;
        dic[k.first] = -1;
        dic[k.second] = -2;

        int ans = 0;
        stack<int> st;
        for (auto& c : s)
        {
            if (c == k.first)
            {
                st.push(dic[c]);
                continue;
            }

            int temp = 0;
            while (!st.empty() && st.top() != dic[k.first] && st.top() != dic[k.second])
            {
                temp += st.top();
                st.pop();
            }
            if (st.empty() || st.top() != dic[k.first])
            {
                st.push(temp);
                st.push(dic[c]);
                continue;
            }

            st.pop();
            temp += 2;
            while (!st.empty() && st.top() != dic[k.first] && st.top() != dic[k.second])
            {
                temp += st.top();
                st.pop();
            }
            ans = max(ans, temp);
            st.push(temp);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.longestValidParentheses(s);
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
