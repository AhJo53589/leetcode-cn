
//////////////////////////////////////////////////////////////////////////
void rotate(vector<int>& nums, int k)
{
	k = k % nums.size();

	int iLen = nums.size();
	while (k > 0 && iLen > 1 && iLen != k)
	{
		for (int i = iLen - 1; i > k - 1; i--)
		{
			swap(nums[i], nums[i - k]);
		}

		int tmp = k;
		k = k - iLen % k;
		iLen = tmp;
	}
}

//////////////////////////////////////////////////////////////////////////
//void rotate(vector<int>& nums, int k)
//{
//	k = k >= nums.size() ? k - nums.size() : k;
//	if (k)
//	{
//		reverse(nums.begin(), nums.end() - k);
//		reverse(nums.end() - k, nums.end());
//		reverse(nums.begin(), nums.end());
//	}
//}

//////////////////////////////////////////////////////////////////////////
//void rotate(vector<int>& nums, int k)
//{
//	k = nums.size() - k % nums.size();
//	auto it_k = nums.begin() + k;
//	std::rotate(nums.begin(), it_k, nums.end());
//}

//////////////////////////////////////////////////////////////////////////
//void rotate(vector<int>& nums, int k)
//{
//	k = nums.size() - k % nums.size();
//	list<int> lst(nums.begin(), nums.end());
//	auto it_k = lst.begin();
//	while (k--) it_k++;
//	lst.splice(lst.begin(), lst, it_k, lst.end());
//	copy(lst.begin(), lst.end(), nums.begin());
//}

//////////////////////////////////////////////////////////////////////////
//void rotate(vector<int>& nums, int k)
//{
//	k = nums.size() - k % nums.size();
//	vector<int> vct;
//	for (auto i = k; i < nums.size(); i++)
//	{
//		vct.push_back(nums[i]);
//	}
//	for (auto i = 0; i < k; i++)
//	{
//		vct.push_back(nums[i]);
//	}
//	swap(nums, vct);
//}


//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums, int k)
{
	rotate(nums,k);
	return nums;
}

//#define USE_SOLUTION_CUSTOM
//void _solution_custom(TestCases &tc)
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
	return "../../problems/rotate-array/tests.txt";
}

