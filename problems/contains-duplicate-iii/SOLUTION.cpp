


//////////////////////////////////////////////////////////////////////////
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
{
	set<double> _set;
	for (int i = 0; i < nums.size(); ++i)
	{
		auto s = _set.lower_bound((double)nums[i] - (double)t);
		if (s != _set.end() && *s <= (double)nums[i] + (double)t) return true;

		_set.insert(nums[i]);
		if (_set.size() > k) _set.erase(nums[i - k]);
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& nums, int k, int t)
{
	return containsNearbyAlmostDuplicate(nums,k,t);
}

//#define USE_SOLUTION_CUSTOM
//bool _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/contains-duplicate-iii/tests.txt";
}

