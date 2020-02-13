


//////////////////////////////////////////////////////////////////////////
vector<vector<int>> diagonalSort(vector<vector<int>>& mat)
{
	vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), 0));

	int m = mat.size();
	int n = mat[0].size();
	for (int x = 0; x < m + n - 1; x++)
	{
		int ti = (x < m) ? m - 1 - x : 0;
		int tj = (x < m) ? 0 : x - (m - 1);
		vector<int> temp;
		while (ti < m && tj < n)
		{
			temp.push_back(mat[ti++][tj++]);
		}
		sort(temp.begin(), temp.end());

		ti = (x < m) ? m - 1 - x : 0;
		tj = (x < m) ? 0 : x - (m - 1);
		int i = 0;
		while (ti < m && tj < n)
		{
			ans[ti++][tj++] = temp[i++];
		}
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<vector<int>>& mat)
{
	return diagonalSort(mat);
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

