


//////////////////////////////////////////////////////////////////////////
vector<int> productExceptSelf(vector<int>& nums)
{
	auto calc = [](int i, int &k, vector<int> &ret, vector<int> &nums) { ret[i] *= k; k *= nums[i]; };
	vector<int> ret(nums.size(), 1);
	int k = 1;
	for (int i = 0; i < nums.size(); i++) calc(i, k, ret, nums);
	k = 1;
	for (int i = nums.size() - 1; i >= 0; i--) calc(i, k, ret, nums);
	return ret;
}

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums)
{
	return productExceptSelf(nums);
}

//#define USE_SOLUTION_CUSTOM
//vector<int> _solution_custom(TestCases &tc)
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
	return "../../problems/product-of-array-except-self/tests.txt";
}

