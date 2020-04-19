
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) 
    {
        const string croak = "croak";
        unordered_map<char, int> dic;
        for (int i = 0; i < croak.size(); i++)
        {
            dic[croak[i]] = i;
        }

        vector<int> cnt(croak.size(), 0);
        int ans = 0;
        int start = 0;
        for (auto c : croakOfFrogs)
        {
            if (dic[c] == 0 || cnt[dic[c] - 1] > 0)
            {
                if (dic[c] != 0)
                {
                    cnt[dic[c] - 1]--;
                }
                start += (dic[c] == 0);
                cnt[dic[c]]++;
                ans = dic[c] == 0 ? max(ans, start - cnt[4]) : ans;
                continue;
            }
            return -1;
        }

        for (int i = 0; i < cnt.size() - 1; i++)
        {
            if (cnt[i] != 0) return -1;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string croakOfFrogs)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << croakOfFrogs << endl;
    Solution sln;
    return sln.minNumberOfFrogs(croakOfFrogs);
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
