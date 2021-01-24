
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
		vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[i].size(); j++) {
				if (i == 0 && j == 0) {
					dp[i][j] = matrix[i][j];
				}
				else if (i == 0) {
					dp[i][j] = dp[i][j - 1] ^ matrix[i][j];
				}
				else if (j == 0) {
					dp[i][j] = dp[i - 1][j] ^ matrix[i][j];
				}
				else {
                    dp[i][j] = dp[i - 1][j - 1] ^ dp[i][j - 1] ^ dp[i - 1][j] ^ matrix[i][j];
				}
                pq.push(dp[i][j]);
                if (pq.size() > k) {
                    pq.pop();
                }
			}
		}
		return pq.top();
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& matrix, int k)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.kthLargestValue(matrix, k);
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
