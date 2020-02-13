
//////////////////////////////////////////////////////////////////////////
void backtrack(vector<int> &nums, vector<vector<int>> &res, int i)
{
	if (i == nums.size()) res.push_back(nums);

	for (int j = i; j < nums.size(); j++)
	{
		swap(nums[i], nums[j]);
		backtrack(nums, res, i + 1);
		swap(nums[i], nums[j]);
	}
}

vector<vector<int>> permute(vector<int>& nums)
{
	vector<vector<int>> res;
	backtrack(nums, res, 0);
	return res;
}


//////////////////////////////////////////////////////////////////////////
//vector<vector<int>> permute(vector<int>& nums) 
//{
//    vector<vector<int>> ans;
//    sort(nums.begin(), nums.end());
//    ans.push_back(nums);
//    while(next_permutation(nums.begin(), nums.end()))
//    {
//        ans.push_back(nums);
//    }
//    return ans;
//}

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<int>& nums)
{
	return permute(nums);
}

//#define USE_SOLUTION_CUSTOM
//vector<vector<int>> _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

