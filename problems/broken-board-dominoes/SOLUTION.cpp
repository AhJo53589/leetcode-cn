
//////////////////////////////////////////////////////////////////////////
//int domino(int n, int m, vector<vector<int>>& broken) {
//	int a[10], f[10][256], ans = 0, o[256], i, j, k;
//	memset(a, 0, sizeof(a));
//	for (auto b : broken)a[b[0]] |= 1 << b[1];
//	memset(f, 128, sizeof(f));
//	f[0][(1 << m) - 1] = 0;
//	for (i = 1; i < 1 << m; i++)o[i] = o[i >> 1] + (i & 1);
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < 1 << m; j++)f[i + 1][0] = max(f[i + 1][0], f[i][j]);
//		if (i)for (j = 0; j < 1 << m; j++)for (k = 0; k < 1 << m; k++)if (!(j&k) && !(a[i - 1] & k) && !(a[i] & k))f[i + 1][k] = max(f[i + 1][k], f[i][j] + o[k]);
//		for (j = 0; j + 1 < m; j++)if (!(a[i] >> j & 1) && !(a[i] >> j + 1 & 1))for (k = 0; k < 1 << m; k++)if (!(k >> j & 1) && !(k >> j + 1 & 1))f[i + 1][k | 1 << j | 1 << j + 1] = max(f[i + 1][k | 1 << j | 1 << j + 1], f[i + 1][k] + 1);
//	}
//	for (i = 0; i < 1 << m; i++)ans = max(ans, f[n][i]);
//	return ans;
//}

//////////////////////////////////////////////////////////////////////////
int domino(int n, int m, vector<vector<int>>& broken) 
{
	return 0;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, int m, vector<vector<int>>& broken)
{
	return domino(n,m,broken);
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

