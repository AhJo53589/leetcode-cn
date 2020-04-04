
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction)
    {
        sort(satisfaction.rbegin(), satisfaction.rend());
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < satisfaction.size(); i++)
        {
            sum += satisfaction[i];
            if (sum < 0) break;
            ans += sum;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& satisfaction)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.maxSatisfaction(satisfaction);
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
