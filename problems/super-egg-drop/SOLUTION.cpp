
//int superEggDrop(int K, int N)	// 4ms
//{
//	int dp[K + 1];
//	fill(dp, dp + K + 1, 0);
//	int m = 0;
//	while (dp[K] < N) {
//		for (int i = K; i >= 1; i--)
//			dp[i] = dp[i] + dp[i - 1] + 1;
//		m++;
//	}
//	return m;
//}

//typedef vector<vector<int>> MI;
//typedef vector<int> VI;
//int superEggDrop(int K, int N)	// 8ms
//{
//	if (K == 0 || N == 0) {
//		return 0;
//	}
//
//	if (N == 1) {
//		return 1;
//	}
//
//	if (K == 1) {
//		return N;
//	}
//	MI mi;
//	VI vi;
//	for (int j = 0; j < K + 1; ++j) {
//		vi.push_back(0);
//	}
//	mi.push_back(vi);
//	for (int x = 1; x < N + 1; ++x) {
//		VI vi;
//		vi.push_back(0);
//		vi.push_back(x);
//
//		int n = 0;
//		for (int k = 2; k < K + 1; ++k) {
//			VI& tmp = mi[x - 1];
//			n = tmp[k - 1] + tmp[k] + 1;
//			vi.push_back(n);
//		}
//
//		if (n >= N) {
//			return x;
//		}
//
//		mi.push_back(vi);
//	}
//
//	return N;
//}

//////////////////////////////////////////////////////////////////////////
int calcMaximumCoverage(int iTime, int K)
{
	// 有K个蛋，行动ans次，计算能判断多少层

	if (iTime == 1) return 2;		// 如果只有1次行动了，无论有几个蛋，都只能判断出2层
	if (K == 1) return iTime + 1;	// 如果只有1个蛋了，蛋不能碎，只能一层一层判断，可以判断出ans + 1层

	// 行动一次，扔个蛋，计算蛋碎了的情况下能判断多少层 + 蛋没碎的情况能判断多少层
	return calcMaximumCoverage(iTime - 1, K - 1) + calcMaximumCoverage(iTime - 1, K);
}

int superEggDrop(int K, int N)	// 8ms
{
	int ans = 1;
	while (calcMaximumCoverage(ans, K) < N + 1)
	{
		++ans;
	}
	return ans;
}


//////////////////////////////////////////////////////////////////////////
int _solution_run(int K, int N)
{
	return superEggDrop(K,N);
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
	return "../../problems/super-egg-drop/tests.txt";
}

