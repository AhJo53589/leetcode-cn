


//////////////////////////////////////////////////////////////////////////
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int m = nums1.size();
	int n = nums2.size();
	if (m > n) return findMedianSortedArrays(nums2, nums1);
	if (m + n == 1) return nums2[0];

	bool odd = (m + n) % 2 == 1;
	int i1 = 0;
	int i2 = 0;
	int iPrev2 = 0;
	int iPrev = 0;

	while (i1 + i2 < (m + n) / 2 + 1)
	{
		iPrev2 = iPrev;
		if (odd && i1 == m) return nums2[n - (m + n) / 2 - 1];
		else if (odd && i2 == n) return nums1[m - (m + n) / 2 - 1];
		else if (!odd && i1 == m) iPrev = nums2[i2++];
		else if (!odd && i2 == n) iPrev = nums1[i1++];
		else iPrev = (nums1[i1] < nums2[i2]) ? nums1[i1++] : nums2[i2++];
	}
	return odd ? iPrev : (double)(iPrev + iPrev2) / 2;
}


//////////////////////////////////////////////////////////////////////////
double _solution_run(vector<int>& nums1, vector<int>& nums2)
{
	return findMedianSortedArrays(nums1,nums2);
}

//#define USE_SOLUTION_CUSTOM
//double _solution_custom(TestCases &tc)
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
	return "../../problems/median-of-two-sorted-arrays/tests.txt";
}

