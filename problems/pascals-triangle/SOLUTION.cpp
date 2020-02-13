
//////////////////////////////////////////////////////////////////////////
//vector<vector<int>> generate(int numRows)
//{
//	vector<vector<int>> m;
//	for (int i = 1; i <= numRows; i++)
//	{
//		vector<int> n;
//		for (int j = 0; j < i; j++)
//		{
//			if (j == 0 || j == i - 1) n.emplace_back(1);
//			else n.emplace_back(m[i - 2][j - 1] + m[i - 2][j]);
//		}
//		m.emplace_back(n);
//	}
//	return m;
//}

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> generate(int numRows)
{
	vector<vector<int>> m;
	for (int i = 1; i <= numRows; i++)
	{
		vector<int> n;
		for (int j = 0; j < i; j++)
		{
			if (j == 0 || j == i - 1) n.push_back(1);
			else n.push_back(m[i - 2][j - 1] + m[i - 2][j]);
		}
		m.push_back(n);
	}
	return m;
}

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(int numRows)
{
	return generate(numRows);
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

