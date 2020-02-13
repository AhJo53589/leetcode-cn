
//////////////////////////////////////////////////////////////////////////
//void wiggleSort(vector<int>& nums) {
//	if (2 > nums.size()) {
//		return;
//	}
//
//	int nums_size = nums.size();
//	auto midptr = nums.begin() + nums_size / 2;
//	nth_element(nums.begin(), midptr, nums.end());
//	int mid = *midptr;
//#define A(i) nums[(1+2*(i)) % (nums_size|1)]
//	int i = 0, j = 0, k = nums_size - 1;
//	while (j <= k) {
//		if (A(j) > mid)
//			swap(A(i++), A(j++));
//		else if (A(j) < mid)
//			swap(A(j), A(k--));
//		else
//			j++;
//	}
//}

//////////////////////////////////////////////////////////////////////////
void wiggleSort(vector<int>& nums) 
{
	vector<int> tmp(nums.begin(), nums.end());
	int len = nums.size();
	int k = (len + 1) >> 1;
	int j = len;
	sort(tmp.begin(), tmp.end());
	for (int i = 0; i < len; ++i) {
		nums[i] = i & 1 ? tmp[--j] : tmp[--k];
	}
}

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums)
{
	wiggleSort(nums);
	return nums;
}

//#define USE_SOLUTION_CUSTOM
//void _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

