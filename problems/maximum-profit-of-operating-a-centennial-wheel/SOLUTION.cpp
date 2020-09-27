
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int profit = 0;
        int maxProfit = 0;
        int ans = -1;
        int waitCnt = 0;
        
        int turn = 0;
        while (waitCnt != 0 || turn < customers.size()) {
            // cout << "--[turn]-- " << turn << endl;
            waitCnt += (turn < customers.size()) ? customers[turn] : 0;
            // cout << "waitCnt = " << waitCnt << endl;
            int upCnt = min(waitCnt, 4);
            // cout << "upCnt = " << upCnt << endl;
            waitCnt -= upCnt;
            // cout << "waitCnt = " << waitCnt << endl;
            profit += upCnt * boardingCost - runningCost;
            // cout << "profit = " << profit << endl;
            if (profit > maxProfit) {
                maxProfit = profit;
                ans = turn + 1;
                // cout << "ans = " << ans << endl;
            }
            turn++;
        }
        
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& customers, int boardingCost, int runningCost)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.minOperationsMaxProfit(customers, boardingCost, runningCost);
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
