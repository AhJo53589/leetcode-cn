
//////////////////////////////////////////////////////////////////////////
//class NumMatrix
//{
//public:
//	NumMatrix(vector<vector<int>>& matrix) : m_matrix(matrix)
//	{
//		for (auto m : matrix)
//		{
//			m_partial.push_back(vector<int>());
//			partial_sum(m.begin(), m.end(), back_inserter(m_partial.back()));
//		}
//	}
//
//	int sumRegion(int row1, int col1, int row2, int col2) 
//	{
//		int ans = 0;
//		for (int i = row1; i <= row2; i++)
//		{
//			ans += m_partial[i][col2] - m_partial[i][col1] + m_matrix[i][col1];
//		}
//		return ans;
//	}
//	vector<vector<int>> m_matrix;
//	vector<vector<int>> m_partial;
//};
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

//////////////////////////////////////////////////////////////////////////
class NumMatrix
{
public:
	NumMatrix(vector<vector<int>>& matrix) : dp(matrix.size() + 1, vector<int>())
	{
		if (matrix.empty()) return;
		for (size_t i = 0; i < dp.size(); i++)
		{
			dp[i].resize(matrix[0].size() + 1);
		}

		dp[1][1] = matrix[0][0];
		for (size_t i = 1; i < matrix[0].size(); i++)
		{
			dp[1][i + 1] = matrix[0][i] + dp[1][i];
		}
		for (size_t i = 1; i < matrix.size(); i++)
		{
			dp[i + 1][1] = matrix[i][0] + dp[i][1];
		}
		for (size_t i = 1; i < matrix.size(); i++)
		{
			for (size_t j = 1; j < matrix[i].size(); j++)
			{
				dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j] - dp[i][j] + matrix[i][j];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2)
	{
		return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
	}
	vector<vector<int>> dp;
};



//////////////////////////////////////////////////////////////////////////
//int _solution_run()
//{
//}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{
	vector<vector<int>> matrix(tc.get<vector<vector<int>>>());
	NumMatrix nm(matrix);
	vector<vector<int>> params(tc.get<vector<vector<int>>>());
	string ans = "[null";
	for (auto p : params)
	{
		int t = nm.sumRegion(p[0], p[1], p[2], p[3]);
		ans += "," + to_string(t);
	}
	ans += "]";
	return ans;
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

