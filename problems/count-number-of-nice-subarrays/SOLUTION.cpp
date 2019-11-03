


//////////////////////////////////////////////////////////////////////////
int numberOfSubarrays(vector<int>& nums, int k)
{
	int ans = 0;
	int cnt = 0;
	int a = 1;
	int b = 1;

	int i = 0;
	for (int j = i; j < nums.size(); j++)
	{
		if (nums[j] & 1)
		{
			cnt++;
		}
		else if (cnt == k)
		{
			b++;
		}

		if (cnt > k)
		{
			while (!(nums[i++] & 1)) a++;
			cnt--;
			ans += a * b;
			a = 1;
			b = 1;
		}
	}

	if (cnt < k) return 0;

	while (!(nums[i++] & 1)) a++;
	ans += a * b;
	return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums, int k)
{
	return numberOfSubarrays(nums,k);
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
	return "../../problems/count-number-of-nice-subarrays/tests.txt";
}

