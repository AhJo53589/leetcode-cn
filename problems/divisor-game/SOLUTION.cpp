


//////////////////////////////////////////////////////////////////////////
bool divisorGame(int N) 
{
    vector<bool> dp(N, true);
    dp[0] = false;
    for (int n = 2; n <= N; n++)
    {
        bool flag = false;
        for (int x = 1; x < n; x++)
        {
            if (n % x != 0) continue;
            if (!dp[n - x - 1])
            {
                flag = true;
                break;
            }
        }
        dp[n - 1] = flag;
    }
    return dp[N - 1];
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(int N)
{
	return divisorGame(N);
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

