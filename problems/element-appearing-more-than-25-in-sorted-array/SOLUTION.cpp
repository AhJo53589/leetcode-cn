


//////////////////////////////////////////////////////////////////////////
int findSpecialInteger(vector<int>& arr) 
{
	int cnt = 0;
	int pre = INT_MAX;
	for (auto n : arr)
	{
		if (pre != n)
		{
			if (cnt > arr.size() / 4)
			{
				return pre;
			}
			cnt = 1;
		}
		else
		{
			cnt++;
		}
		pre = n;
	}
	return pre;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& arr)
{
	return findSpecialInteger(arr);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

