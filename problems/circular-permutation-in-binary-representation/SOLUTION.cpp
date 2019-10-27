
//////////////////////////////////////////////////////////////////////////
vector<int> grayCode(int n) 
{
	vector<int> res;
	for (int i = 0; i < (1 << n); ++i)
		res.push_back(i ^ (i >> 1));
	return res;
}

vector<int> circularPermutation(int n, int start) 
{
	vector<int> ans = grayCode(n);
	auto k = ans.begin();
	while (k != ans.end() && *k != start) k++;
	rotate(ans.begin(), k, ans.end());
	return ans;
}

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(int n, int start)
{
	return circularPermutation(n, start);
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
	return "../../problems/circular-permutation-in-binary-representation/tests.txt";
}

