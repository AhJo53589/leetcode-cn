


//////////////////////////////////////////////////////////////////////////
bool containsNearbyDuplicate(vector<int>& nums, int k)
{
	if (nums.empty()) return false;
	unordered_map<int, int> m;
	for (int i = 0; i < nums.size(); i++)
	{
		if (!m.count(nums[i])) m[nums[i]] = i;
		else if (i - m[nums[i]] <= k) return true;
		else m[nums[i]] = i;
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& nums, int k)
{
	return containsNearbyDuplicate(nums,k);
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
	return "../../problems/contains-duplicate-ii/tests.txt";
}

