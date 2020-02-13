


//////////////////////////////////////////////////////////////////////////
vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) 
{
	vector<vector<int>> ans(mat);
	vector<vector<int>> _m(mat);
	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = 1; j < mat[0].size(); j++)
		{
			_m[i][j] += _m[i][j - 1];
		}
	}

	int m = mat.size();
	int n = mat[0].size();
	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = 0; j < mat[0].size(); j++)
		{
			int m1 = max(i - K, 0);
			int m2 = min(i + K, m - 1);
			int n1 = j - K - 1;
			int n2 = j + K;
			ans[i][j] = 0;
			for (int ii = m1; ii <= m2; ii++)
			{
				ans[i][j] += (n2 < n) ? _m[ii][n2] : _m[ii][n - 1];
				ans[i][j] -= (n1 >= 0) ? _m[ii][n1] : 0;
			}
		}
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<vector<int>>& mat, int K)
{
	return matrixBlockSum(mat,K);
}

//#define USE_SOLUTION_CUSTOM
//vector<vector<int>> _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

