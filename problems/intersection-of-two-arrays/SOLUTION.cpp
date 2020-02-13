


//////////////////////////////////////////////////////////////////////////
vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
	unordered_set<int> set1;
	unordered_set<int> set2;
	for (auto n : nums1) set1.insert(n);
	for (auto n : nums2) set2.insert(n);
	vector<int> rst;
	for (auto n1 : set1)
	{
		for (auto n2 : set2)
		{
			if (n1 == n2) rst.push_back(n1);
		}
	}
	return rst;
}

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums1, vector<int>& nums2)
{
	return intersection(nums1,nums2);
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

