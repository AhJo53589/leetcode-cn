
//int countPrimes(int k)
//{
//	if (k < 3)
//	{
//		return 0;
//	}
//
//	vector<bool> arr(k);
//
//	for (int i = 0; i < k; i++)
//	{
//		arr[i] = true;
//	}
//
//	int m = sqrt(k);
//
//	for (int i = 3; i <= m; i += 2)
//	{
//		if (arr[i])
//		{
//			int step = i + i;
//			for (int j = i + step; j < k; j += step)
//			{
//				arr[j] = false;
//			}
//		}
//	}
//
//	int sum = 1;
//	for (int i = 3; i < k; i += 2)
//	{
//		if (arr[i])
//		{
//			sum++;
//		}
//	}
//
//	return sum;
//}


//////////////////////////////////////////////////////////////////////////
int countPrimes(int n) 
{
	if (n < 3) return 0;

	vector<bool> primeFlag(n);
	primeFlag[2] = true;
	for (long long i = 3; i < n; i += 2)
	{
		primeFlag[i] = true; // 所有奇数标为true，偶数为false
	}
	for (long long i = 3; i < n; i++)
	{
		if (primeFlag[i])
		{
			int cnt = 2;
			while (cnt * i < n)
			{
				// 把i的倍数标为false（因为它们是合数）
				primeFlag[cnt * i] = false;
				cnt++;
			}
		}
	}

	int cnt = 1;
	for (long long i = 3; i < n; i += 2)
	{
		if (primeFlag[i])
		{
			//cout << cnt << ' ' << i << endl;
			cnt++;
		}
	}
	return cnt;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n)
{
	return countPrimes(n);
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
	return "../../problems/count-primes/tests.txt";
}

