//////////////////////////////////////////////////////////////////////////
bool isLine(vector<int>& a, vector<int>& b, vector<int>& c)
{
	long long t1 = ((long long)a[0] - b[0]) * ((long long)a[1] - c[1]);
	long long t2 = ((long long)a[0] - c[0]) * ((long long)a[1] - b[1]);
	return t1 == t2;
}

bool checkStraightLine(vector<vector<int>>& coordinates) 
{
	vector<vector<int>>& c = coordinates;
	if (c.size() < 3) return true;
	for (size_t i = 0; i < c.size() - 2; i++)
	{
		if (!isLine(c[i], c[i + 1], c[i + 2]))
			return false;
	}
	return true;
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<vector<int>>& coordinates) 
{
	return checkStraightLine(coordinates);
}

//#define USE_SOLUTION_CUSTOM
//vector<int> _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}


