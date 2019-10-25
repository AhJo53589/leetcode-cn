
//int rob(vector<int>& nums)
//{
//	int sumOdd = 0;
//	int sumEven = 0;
//	for (int i = 0; i < nums.size(); i++)
//	{
//		if (i % 2 == 0)
//		{
//			sumEven += nums[i];
//			sumEven = max(sumOdd, sumEven);
//		}
//		else
//		{
//			sumOdd += nums[i];
//			sumOdd = max(sumOdd, sumEven);
//		}
//	}
//	return max(sumOdd, sumEven);
//}

//int rob(vector<int>& nums) 
//{
//	// 动态规划
//	if (nums.size() == 0) return 0;
//	if (nums.size() == 1)
//		return nums[0];
//	if (nums.size() == 2)
//		return max(nums[0], nums[1]);
//	nums[2] = nums[0] + nums[2];
//	if (nums.size() == 3)
//		return max(nums[1], nums[2]);
//	for (int i = 3; i < nums.size(); i++)
//	{
//		nums[i] = max(nums[i - 2] + nums[i], nums[i] + nums[i - 3]);
//	}
//	return max(nums[nums.size() - 1], nums[nums.size() - 2]);
//}


//////////////////////////////////////////////////////////////////////////
int rob(vector<int>& nums)
{
	int sumOdd = 0;
	int sumEven = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (i % 2 == 0)
		{
			sumOdd = max(sumOdd, sumEven);
			sumEven += nums[i];
		}
		else
		{
			sumEven = max(sumOdd, sumEven);
			sumOdd += nums[i];
		}
	}
	return max(sumOdd, sumEven);
}


//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
	return rob(nums);
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
	return "../../problems/house-robber/tests.txt";
}

