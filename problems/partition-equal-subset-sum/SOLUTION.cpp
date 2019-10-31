
//////////////////////////////////////////////////////////////////////////
bool DFS(const vector<int>& nums, int start, int curSum, int C)
{
	curSum += nums[start];
	if (curSum == C) return true;

	for (int i = start - 1; i >= 0; --i)
	{
		if (curSum + nums[i] > C) continue;
		return DFS(nums, i, curSum, C);
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////
bool canPartition(vector<int>& nums)
{
	int sum = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		sum += nums[i];
	}
	if (sum % 2 != 0) return false;

	sort(nums.begin(), nums.end());
	int C = sum / 2;
	if (nums.back() > C) return false;

	for (int i = nums.size() - 1; i >= 0; --i)
	{
		if (DFS(nums, i, 0, C)) return true;
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& nums)
{
	return canPartition(nums);
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
	return "../../problems/partition-equal-subset-sum/tests.txt";
}

