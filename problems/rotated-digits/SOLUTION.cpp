
//////////////////////////////////////////////////////////////////////////
//int rotatedDigits(int N) {
//	int count = 0;
//	for (int i = 1; i <= N; i++) {
//		string num = to_string(i);
//		if (num.find_first_of("347") == -1 &&
//			num.find_first_of("2569") != -1) {
//			//cout << count << " : \t" << num << endl;
//			count++;
//		}
//	}
//	return count;
//}

//////////////////////////////////////////////////////////////////////////
//vector<int> dir = { 8,1,0,2,5,6,9 };
//void dfs(int e, int &re, int N, int x) {
//	if (x > N) return;
//	for (int i = 0; i < e; i++) {
//		if (x == 0 && dir[i] == 0) continue;
//		int tx = x * 10 + dir[i];
//		if (tx <= N) re++;
//		dfs(e, re, N, tx);
//	}
//}
//int rotatedDigits(int N) {
//	int ans1 = 0;
//	dfs(3, ans1, N, 0);
//	int ans2 = 0;
//	dfs(7, ans2, N, 0);
//	return ans2 - ans1;
//}

//////////////////////////////////////////////////////////////////////////
const vector<vector<int>> cnt = { { 0,0,1,1,1,2,3,3,3,4 }, { 1,2,3,3,3,4,5,5,6,7 } };
const set<int> s1 = { 3,4,7 };
const set<int> s2 = { 2,5,6,9 };

int calcGood(int n, int d, int f, vector<map<vector<int>, int>> &m)
{
	if (d == 0)
	{
		return cnt[f][n - 1];
	}
	int ans = 0;
	if (m[f].count({ n, d }) == 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (s1.count(i) != 0) continue;
			int tempf = (f || s2.count(i) != 0);
			ans += calcGood(10, d - 1, tempf, m);
		}
		m[f][{n, d}] = ans;
	}
	else
	{
		ans = m[f][{n, d}];
	}
	return ans;
}

int rotatedDigits(int N)
{
	vector<map<vector<int>, int>> m(2, map<vector<int>, int>());

	vector<int> a;
	while (N > 0)
	{
		a.push_back(N % 10);
		N /= 10;
	}

	int ans = 0;
	int f = 0;
	for (size_t i = a.size() - 1; i < a.size(); i--)
	{
		if (i != 0)
		{
			ans += calcGood(a[i], i, f, m);
			if (s1.count(a[i]) != 0) break;
			f = (f || s2.count(a[i]) != 0);
		}
		else
		{
			ans += calcGood(a[i] + 1, i, f, m);
		}
	}
	return ans;
}


//////////////////////////////////////////////////////////////////////////
int _solution_run(int N)
{
	return rotatedDigits(N);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

