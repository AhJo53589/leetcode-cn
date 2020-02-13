


//////////////////////////////////////////////////////////////////////////
vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
{
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());

	int i = 0;
	int j = 0;
	vector<int> nums;
	while (i < nums1.size() && j < nums2.size())
	{
		if (nums1[i] < nums2[j])
		{
			i++;
		}
		else if (nums1[i] > nums2[j])
		{
			j++;
		}
		else
		{
			nums.push_back(nums1[i]);
			i++;
			j++;
		}
	}
	return nums;
}

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums1, vector<int>& nums2)
{
	return intersect(nums1,nums2);
}

//#define USE_SOLUTION_CUSTOM
//vector<int> _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

