
// 容易发现结果只取决于 K，与 N 无关。
// a[i] 由 a[i / 2] 生成，i为偶数时不变，奇数时取反。

// 举个例子：
// a[5]，奇数坐标，等于a[5 / 2] = a[2]取反，a[2]又等于a[1]，a[1]又等于a[0]取反。
// 终止条件就是a[0], 我们知道a[0] = 0;
// 只需要在折半的过程中根据奇偶进行取反即可。

//int kthGrammar(int N, int K)
//{
//	K--; //counting from 0 instead of 1
//	bool r = 0;
//	while (K)
//	{
//		r ^= (K & 1);
//		K /= 2;
//	}
//	return r;
//}


//////////////////////////////////////////////////////////////////////////
int kthGrammar(int N, int K)
{
	if (N == 1) return 0;
	return (kthGrammar(N - 1, (K - 1) / 2 + 1) == 0) ? ((K - 1) % 2) : 1 - ((K - 1) % 2);
}


//////////////////////////////////////////////////////////////////////////
int _solution_run(int N, int K)
{
	return kthGrammar(N,K);
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

