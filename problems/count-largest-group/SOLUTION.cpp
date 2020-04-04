
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int f(int x)
    {
        int cnt = 0;
        while (x != 0)
        {
            cnt += (x % 10);
            x /= 10;
        }
        return cnt;
    }

    int countLargestGroup(int n) 
    {
        unordered_map<int, int> mp;
        for (int i = 1; i <= n; i++)
        {
            mp[f(i)]++;
        }

        int ans = 0;
        int cnt = 0;
        for (auto it : mp)
        {
            if (cnt < it.second)
            {
                cnt = it.second;
                ans = 0;
            }
            ans += (cnt == it.second);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.countLargestGroup(n);
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
