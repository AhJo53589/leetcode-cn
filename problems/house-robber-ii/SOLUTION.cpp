


//////////////////////////////////////////////////////////////////////////
int rob(vector<int>& nums)
{
	if (nums.size() == 1) return nums[0];

	int sumOdd[2] = { 0, 0 };	// 0 == head, 1 == tail
	int sumEven[2] = { 0, 0 };
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (i == 0 && j == 1) continue;	// head only
			if (i == nums.size() - 1 && j == 0) continue;	// tail only
			if (i % 2 == 0)
			{
				sumOdd[j] = max(sumOdd[j], sumEven[j]);
				sumEven[j] += nums[i];
			}
			else
			{
				sumEven[j] = max(sumOdd[j], sumEven[j]);
				sumOdd[j] += nums[i];
			}
		}
	}

	for (int j = 0; j < 2; j++)
	{
		sumOdd[j] = max(sumOdd[j], sumEven[j]);
	}
	return max(sumOdd[0], sumOdd[1]);
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
	return "../../problems/house-robber-ii/tests.txt";
}

