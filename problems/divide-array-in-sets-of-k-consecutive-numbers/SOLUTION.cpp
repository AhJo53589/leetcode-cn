


//////////////////////////////////////////////////////////////////////////
bool isPossibleDivide(vector<int>& nums, int k) 
{
	map<int, int> cnts;
	for (auto n : nums) cnts[n]++;

	for (auto it = cnts.begin(); it != cnts.end(); it++)
	{
		while (it->second != 0)
		{
			int _first = it->first;
			it->second--;
			for (int i = 1; i < k; i++)
			{
				int t = _first + i;
				if (cnts.count(t) == 0) return false;
				if (cnts[t]-- == 0) return false;
			}
		}
	}
	return true;
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& nums, int k)
{
	return isPossibleDivide(nums,k);
}

//#define USE_SOLUTION_CUSTOM
//bool _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

