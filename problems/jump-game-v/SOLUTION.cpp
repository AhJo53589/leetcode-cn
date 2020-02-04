
//////////////////////////////////////////////////////////////////////////
//int maxJumps(vector<int>& arr, int d) 
//{
//	int n = arr.size();
//
//	vector<int> p(n);
//	for (int i = 0; i < n; ++i) p[i] = i;
//	sort(p.begin(), p.end(), [&](int i, int j)
//		{
//			return arr[i] < arr[j];
//		});
//
//	vector<int> f(n);
//	for (int k = 0; k < n; ++k)
//	{
//		int i = p[k];
//		int L = i - 1, R = i + 1;
//		while (L >= 0 && arr[L] < arr[i]) --L;
//		while (R < n && arr[R] < arr[i]) ++R;
//		f[i] = 1;
//		for (int j = L + 1; j <= R - 1; ++j)
//		{
//			if (j != i && abs(j - i) <= d)
//			{
//				f[i] = max(f[i], f[j] + 1);
//			}
//		}
//	}
//	return *max_element(f.begin(), f.end());
//}

//////////////////////////////////////////////////////////////////////////
void maxJumps(vector<int>& arr, int d, int cur, vector<int>& steps, int& ans)
{
	if (steps[cur] != -1) return;

	int l = max(0, cur - d);
	int r = min((int)arr.size() - 1, cur + d);

	int step = 0;
	for (int dirction = -1; dirction <= 1; dirction += 2)
	{
		for (int i = cur + dirction; i <= r && i >= l; i += dirction)
		{
			if (arr[cur] <= arr[i]) break;

			maxJumps(arr, d, i, steps, ans);
			step = max(step, steps[i]);
		}
	}

	steps[cur] = step + 1;
	ans = max(ans, steps[cur]);
}

int maxJumps(vector<int>& arr, int d) 
{
	vector<int> steps(arr.size(), -1);
	int ans = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		maxJumps(arr, d, i, steps, ans);
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& arr, int d)
{
	return maxJumps(arr,d);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
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
	return "../../problems/jump-game-v/tests.txt";
}

