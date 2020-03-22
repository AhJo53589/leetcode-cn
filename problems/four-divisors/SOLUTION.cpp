
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int getDivisors(int num)
    {
        int cnt = 0;
        int ans = 0;
        for (int i = 1; i <= num; i++)
        {
            if (num % i == 0)
            {
                ans += i;
                cnt++;
            }
            if (cnt > 4) return 0;
        }
        if (cnt != 4) return 0;
        return ans;
    }

    int sumFourDivisors(vector<int>& nums)
    {
        int ans = 0;
        for (auto& n : nums)
        {
            ans += getDivisors(n);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.sumFourDivisors(nums);
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
