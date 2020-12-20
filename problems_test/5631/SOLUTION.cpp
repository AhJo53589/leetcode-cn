
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
		vector<int> dp(nums.size(), INT_MIN);
		dp[0] = nums[0];

		deque<int> dq;
		for (int i = min((int)nums.size(), k); i > 0; i--) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            //while (!dq.empty() && i - dq.front() > k) {
            //    dq.pop_front();
            //}
			dq.push_back(i);
		}

		for (int i = 0; i < nums.size(); i++) {
			while (!dq.empty() && nums[dq.back()] < nums[min(i + k, (int)nums.size())]) {
				dq.pop_back();
			}
			while (!dq.empty() && i - dq.front() > k) {
				dq.pop_front();
			}
			for (int j = 0; j < dq.size(); j++) {
				int t = dq[j];
				dp[t] = max(dp[t], dp[i] + nums[t]);
			}
		} 
		return dp.back();
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums, int k)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	printVectorT(nums);
	cout << k << endl;
	Solution sln;
	return sln.maxResult(nums, k);
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
