


//////////////////////////////////////////////////////////////////////////
int threeSumClosest(vector<int>& nums, int target)
{
	int ret = INT_MAX;
	sort(nums.begin(), nums.end());
	int len = nums.size();
	if (len < 3) return 0;
	for (int i = 0; i < len; i++)
	{
		if (i > 0 && nums[i] == nums[i - 1]) continue; // 去重
		int L = i + 1;
		int R = len - 1;
		while (L < R)
		{
			int sum = nums[i] + nums[L] + nums[R];
			int temp = sum - target;
			ret = (abs(temp) < abs(ret)) ? temp : ret;
			if (sum == target) return target;
			if (sum < target) L++;
			else if (sum > target) R--;
		}
	}
	return target + ret;
}


//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums, int target)
{
	return threeSumClosest(nums,target);
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
	return "../../problems/3sum-closest/tests.txt";
}

