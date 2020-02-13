
//int findKthLargest(vector<int>& nums, int k) 
//{
//	int len = nums.size();
//	bool bOrder = k <= len / 2;
//	cout << "bOrder = " << bOrder << endl;
//
//	int t = bOrder ? k : len - k + 1;
//	for (int j = 0; j < len - 1; j++)
//	{
//		for (int i = 0; i < len - 1 - j; i++)
//		{
//			if ([bOrder](int a, int b) { return bOrder ? a > b : b > a; }(nums[i], nums[i + 1]))
//			{
//				swap(nums[i], nums[i + 1]);
//				cout << "swap(nums[" << i << "], nums[" << i + 1 << "]);" << endl;
//				printVectorInt(nums);
//			}
//		}
//		t--;
//		if (t == 0) break;
//		cout << "t = " << t << endl << endl;
//	}
//	return bOrder ? nums[len - k] : nums[k - 1];
//}

//////////////////////////////////////////////////////////////////////////
int findKthLargest(vector<int>& nums, int k)
{
	int len = nums.size();
	bool bOrder = k <= len / 2;
	int t = bOrder ? k : len - k + 1;
	for (int j = 0; j < len - 1; j++)
	{
		for (int i = 0; i < len - 1 - j; i++)
		{
			if ([bOrder](int a, int b) { return bOrder ? a > b : b > a; }(nums[i], nums[i + 1]))
			{
				swap(nums[i], nums[i + 1]);
			}
		}
		if (t-- == 0) break;
	}
	return bOrder ? nums[len - k] : nums[k - 1];
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums, int k)
{
	return findKthLargest(nums,k);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

