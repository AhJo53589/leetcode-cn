
//////////////////////////////////////////////////////////////////////////
//vector<vector<int>> subsets(vector<int>& nums) {
//	vector<vector<int>> res(1);
//	for (int i = 0; i < nums.size(); i++) {
//		int cnt = res.size();
//		for (int j = 0; j < cnt; j++) {
//			vector<int> tmp = res[j];
//			tmp.push_back(nums[i]);
//			res.push_back(tmp);
//		}
//	}
//	return res;
//}

//////////////////////////////////////////////////////////////////////////
//void backtrack(vector<int> &nums, vector<vector<int>> &res, vector<int> record, int n)
//{
//	if (n == nums.size()) return;
//	for (int i = n; i < nums.size(); i++)
//	{
//		record.push_back(nums[i]);
//		res.push_back(record);
//		backtrack(nums, res, record, i + 1);
//		record.pop_back();
//	}
//}
//
//vector<vector<int>> subsets(vector<int>& nums)
//{
//	vector<vector<int>> res;
//	vector<int> record;
//	res.push_back(record);
//	backtrack(nums, res, record, 0);
//	return res;
//}

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> subsets(vector<int>& nums) {
	int S = nums.size();
	int N = (1 << S);
	vector<vector<int>> res;
	for (int i = 0; i < N; ++i) 
	{
		vector<int> v;
		for (int j = 0; j < S; ++j)
		{
			if (i & (1 << j)) v.push_back(nums[j]);
		}
		res.push_back(v);
	}
	return res;
}

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<int>& nums)
{
	return subsets(nums);
}

//#define USE_SOLUTION_CUSTOM
//vector<vector<int>> _solution_custom(TestCases &tc)
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
	return "../../problems/subsets/tests.txt";
}

