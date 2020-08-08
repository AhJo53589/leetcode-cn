
//////////////////////////////////////////////////////////////////////////
//class Solution {
//public:
//    int tallestBillboard(vector<int>& rods) {
//		int sum = accumulate(rods.begin(), rods.end(), 0);
//
//		vector<int> dp(sum + 1, INT_MAX);
//		vector<bool> vi(sum + 1, false);
//		dp[0] = 0;
//		vi[0] = true;
//
//		for (auto r : rods) {
//			for (int x = sum; x >= 0; x--) {
//				if (x - r >= 0 && vi[x - r]) {
//					vi[x] = true;
//					dp[x] = min(dp[x], dp[x - r] + r);
//				}
//				if (x - 2 * r >= 0 && vi[x - 2 * r]) {
//					vi[x] = true;
//					dp[x] = min(dp[x], dp[x - 2 * r]);
//				}
//			}
//		}
//
//		return (sum - dp[sum]) / 2;
//    }
//};

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
		if (rods.size() < 2) return 0;
		int sum = accumulate(rods.begin(), rods.end(), 0);
		sort(rods.rbegin(), rods.rend());
		dfs(rods, 0, rods[0], 0, sum - rods[0]);
		dfs(rods, 0, 0, 0, sum - rods[0]);
		return ans;
    }

	void dfs(vector<int>& rods, int idx, int left, int right, int remain) {
		if (abs(left - right) > remain || (left + right + remain) <= ans * 2) return;
		
		if (left == right) {
			ans = max(ans, left);
		}

		if (++idx == rods.size()) return;

		remain -= rods[idx];
		dfs(rods, idx, left + rods[idx], right, remain);
		dfs(rods, idx, left, right + rods[idx], remain);
		dfs(rods, idx, left, right, remain);
	}

private:
	int ans = 0;
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& rods)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.tallestBillboard(rods);
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
