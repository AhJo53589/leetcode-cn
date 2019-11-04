//////////////////////////////////////////////////////////////////////////
//int numberOfSubarrays(vector<int>& nums, int k)
//{
//	int ans = 0;
//	int cnt = 0;
//	int a = 1;
//	int b = 1;
//
//	int i = 0;
//	for (int j = 0; j < nums.size(); j++)
//	{
//		cnt += (nums[j] & 1);
//		b += (!(nums[j] & 1) && (cnt == k));
//
//		if (cnt > k)
//		{
//			while (!(nums[i++] & 1)) a++;
//			ans += a * b;
//			a = 1;
//			b = 1;
//			cnt--;
//		}
//	}
//	if (cnt < k) return 0;
//
//	while (!(nums[i++] & 1)) a++;
//	ans += a * b;
//	return ans;
//}

//////////////////////////////////////////////////////////////////////////
int numberOfSubarrays(vector<int>& nums, int k)
{
	vector<int> odd;
	odd.push_back(-1);

	int ans = 0;
	int i = 1;
	for (int j = 0; j <= nums.size(); j++)
	{
		if (j == nums.size() || (nums[j] & 1))
		{
			odd.push_back(j);
		}

		if (odd.size() - i > k)
		{
			int a = odd[i] - odd[i - 1];
			int b = j - odd[odd.size() - 2];
			ans += a * b;
			i++;
		}
	}
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

