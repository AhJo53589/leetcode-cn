
//////////////////////////////////////////////////////////////////////////
bool calc(vector<int> &vec, int k, int d)
{
	int val = 0;
	int cnt = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		val += vec[i];
		if (val >= d && cnt < k)
		{
			val = 0;
			cnt++;
		}
	}
	return val >= d;
}

int maximizeSweetness(vector<int>& sweetness, int K) 
{
	int lb = 0, ub = 1e10;
	while (ub - lb > 1)
	{
		int mid = lb + (ub - lb) / 2;
		if (calc(sweetness, K, mid)) lb = mid;
		else ub = mid;
	}
	return lb;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& sweetness, int K)
{
	return maximizeSweetness(sweetness,K);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

//#define USE_GET_TEST_CASES_FILESTREAM
//string _get_test_cases_filestream()
//{
//	return "../../problems/divide-chocolate/tests.txt";
//}

