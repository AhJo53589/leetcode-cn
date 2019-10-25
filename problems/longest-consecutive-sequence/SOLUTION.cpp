
//////////////////////////////////////////////////////////////////////////
//int longestConsecutive(vector<int>& nums) {
//	if (nums.empty()) {
//		return 0;
//	}
//	unordered_set<int> myset(nums.begin(), nums.end());
//	int res = 0;
//
//	for (auto &num : nums) {
//		if (myset.count(num - 1) == 0) {
//			int x = num + 1;
//			while (myset.count(x)) {
//				x++;
//			}
//			res = max(res, x - num);
//		}
//	}
//	return res;
//}


//////////////////////////////////////////////////////////////////////////
int longestConsecutive(vector<int>& nums)
{
	if (nums.size() == 0) return 0;
	sort(nums.begin(), nums.end());

	int ans = 1;
	int temp = 1;
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] == nums[i - 1]) continue;
		temp = (nums[i] == nums[i - 1] + 1) ? temp + 1 : 1;
		ans = max(ans, temp);
	}

	return ans;
}


//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
	return longestConsecutive(nums);
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

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/longest-consecutive-sequence/tests.txt";
}

