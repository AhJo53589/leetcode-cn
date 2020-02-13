
//// 循环
//bool isPowerOfThree(int n) 
//{
//	if (n == 1) return true;
//	long m = 1;
//	while (m < n)
//	{
//		m *= 3;
//		if (m == n)
//			return true;
//	}
//	return false;
//}
//
//// 递归
//bool isPowerOfThree(int n) 
//{
//	if (n == 1) return true;
//	else if (n == 0) return false;
//	else return isPowerOfThree(n / 3) && n % 3 == 0;
//}


//////////////////////////////////////////////////////////////////////////
// 3的幂次质因子只有3，而整数范围内的3的幂次最大是1162261467
bool isPowerOfThree(int n)
{
	return n > 0 && 1162261467 % n == 0;
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(int n)
{
	return isPowerOfThree(n);
}

//#define USE_SOLUTION_CUSTOM
//bool _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

