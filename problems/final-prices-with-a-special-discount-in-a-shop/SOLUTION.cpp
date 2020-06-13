
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans(prices.size(), 0);
        for (int i = 0; i < prices.size(); i++) {
            ans[i] = prices[i];
            for (int j = i + 1; j < prices.size(); j++) {
                if (prices[j] > prices[i]) continue;
                ans[i] -= prices[j];
                break;
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& prices)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.finalPrices(prices);
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
