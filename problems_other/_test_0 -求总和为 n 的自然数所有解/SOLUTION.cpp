
//////////////////////////////////////////////////////////////////////////
// 求总和为 n 的自然数所有解

//输入：3
//输出： [[1, 1, 1], [1, 2]]
//
//输入：4
//输出： [[1, 1, 1, 1], [1, 1, 2], [1, 3], [2, 2]]


//////////////////////////////////////////////////////////////////////////
bool getNext(vector<int>& a)
{
	if (a.size() <= 1) return false;

	//int sum = a[a.size() - 1] + a[a.size() - 2] - (a[a.size() - 2] + 1);
	int sum = a[a.size() - 1] - 1;
	a.pop_back();
	a.back()++;

	size_t i = a.size() - 1;
	while (sum >= a[i])
	{
		sum -= a[i];
		a.push_back(a[i]);
	}
	a.back() += sum;

	return (a.size() > 1);
}

vector<vector<int>> combine(int n) 
{
	vector<vector<int>> ans;
	vector<int> a(n, 1);

	do
	{
		ans.push_back(a);
	} while (getNext(a));

	return ans;
}

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(int n)
{
	return combine(n);
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
	return "../../problems/_test_0/tests.txt";
}

