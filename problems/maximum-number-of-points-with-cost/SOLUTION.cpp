
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
		vector<long long> dp(points[0].size(), 0);
        vector<long long> pre(points[0].size(), 0);
		for (int i = 0; i < dp.size(); i++) {
			dp[i] = (long long)points[0][i];
		}

		for (int i = 1; i < points.size(); i++) {
			change(dp);
			swap(dp, pre);
			for (int j = 0; j < points[i].size(); j++) {
				dp[j] = max(dp[j], (long long)points[i][j] + pre[j]);
			}
		}
		return *max_element(dp.begin(), dp.end());
    }

	void change(vector<long long>& dp) {
		for (int i = 1; i < dp.size(); i++) {
			dp[i] = max(dp[i], dp[i - 1] - 1);
		}
		for (int i = (int)dp.size() - 2; ~i; i--) {
			dp[i] = max(dp[i], dp[i + 1] - 1);
		}
	}
};

//////////////////////////////////////////////////////////////////////////
long _solution_run(vector<vector<int>>& points)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.maxPoints(points);
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
