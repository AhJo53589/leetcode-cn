
//////////////////////////////////////////////////////////////////////////
//vector<string> generateParenthesis(int n) {
//	vector<string> ans;
//	if (n == 0)
//		return ans;
//	string cur;
//	search(ans, cur, 0, 0, n);
//	return ans;
//}
//void search(vector<string> &ans, string cur, int open, int close, int n)
//{
//	if (cur.size() == 2 * n)
//		ans.push_back(cur);
//	if (open < n)
//		search(ans, cur + '(', open + 1, close, n);
//	if (close < open)
//		search(ans, cur + ')', open, close + 1, n);
//}

//////////////////////////////////////////////////////////////////////////
vector<string> generateParenthesis(int n)
{
	vector<int> res_left;
	vector<string> res;
	res_left.push_back(0);
	res.push_back("");

	for (int i = 0; i < 2 * n; i++)
	{
		int len = res.size();
		for (int j = 0; j < len; j++)
		{
			int left = res_left[j];
			if (left < n)
			{
				res_left.push_back(left + 1);
				res.push_back(res[j] + "(");
			}

			if (i - left < left)
			{
				res_left.push_back(left);
				res.push_back(res[j] + ")");
			}
		}
		res_left.erase(res_left.begin(), res_left.begin() + len);
		res.erase(res.begin(), res.begin() + len);
	}
	return res;
}

//////////////////////////////////////////////////////////////////////////
vector<string> _solution_run(int n)
{
	return generateParenthesis(n);
}

//#define USE_SOLUTION_CUSTOM
//vector<string> _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

