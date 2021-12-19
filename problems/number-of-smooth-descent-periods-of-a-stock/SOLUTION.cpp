
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        for (int i = 0; i < prices.size(); ) {
            int j = 0;
            while (i + j < prices.size() && prices[i + j] + j == prices[i]) {
                j++;
            }
            ans += 1LL * (j + 1) * j / 2;
            i += j;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
long _solution_run(vector<int>& prices)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.getDescentPeriods(prices);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
