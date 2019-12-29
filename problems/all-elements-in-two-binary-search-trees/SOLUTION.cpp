
//////////////////////////////////////////////////////////////////////////
void dfs(vector<int>& arr, int i, vector<bool>& vi, bool& ans)
{
	if (ans) return;
	if (i < 0 || i >= arr.size()) return;
	if (vi[i]) return;
	vi[i] = true;
	if (arr[i] == 0)
	{
		ans = true;
		return;
	}
	dfs(arr, i + arr[i], vi, ans);
	dfs(arr, i - arr[i], vi, ans);
}

bool canReach(vector<int>& arr, int start) 
{
	bool ans = false;
	vector<bool> vi(arr.size(), false);
	dfs(arr, start, vi, ans);
	return ans;
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& arr, int start)
{
	return canReach(arr,start);
}

//#define USE_SOLUTION_CUSTOM
//bool _solution_custom(TestCases &tc)
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
	return "../../problems/all-elements-in-two-binary-search-trees/tests.txt";
}

