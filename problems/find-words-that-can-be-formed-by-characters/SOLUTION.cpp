
//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
    int countCharacters(vector<string>& words, string chars)
    {
        unordered_map<char, int> cnt;
        for (auto c : chars)
        {
            cnt[c]++;
        }
        int ans = 0;
        for (auto w : words)
        {
            bool flag = true;
            unordered_map<char, int> cntw;
            for (auto c : w)
            {
                if (++cntw[c] > cnt[c])
                {
                    flag = false;
                    break;
                }
            }
            ans += (flag) ? w.size() : 0;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) 
    {
        vector<int> cnt(26, 0);
        for (auto c : chars)
        {
            cnt[(int)c - 'a']++;
        }
        int ans = 0;
        for (auto w : words)
        {
            bool flag = true;
            vector<int> cntw(26, 0);
            for (auto c : w)
            {
                if (++cntw[(int)c - 'a'] > cnt[(int)c - 'a'])
                {
                    flag = false;
                    break;
                }
            }
            ans += (flag) ? w.size() : 0;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<string>& words, string chars)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.countCharacters(words, chars);
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
