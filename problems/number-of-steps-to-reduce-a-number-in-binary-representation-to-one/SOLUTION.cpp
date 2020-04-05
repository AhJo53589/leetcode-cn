
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numSteps(string s) 
    {
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0') continue;
            s = s.substr(i, s.size() - i);
            break;
        }
        while (s.back() == '0')
        {
            ans++;
            s.pop_back();
        }
        if (s.size() == 1) return ans;

        s.insert(s.begin(), '0');
        for (int i = s.size() - 1; i > 0;)
        {
            int cnt = 1;
            while (i - cnt >= 0 && s[i - cnt] == '1')
            {
                cnt++;
            }
            ans += cnt + 1;
            i -= cnt;
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

    cout << s << endl;
    Solution sln;
    return sln.numSteps(s);
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
