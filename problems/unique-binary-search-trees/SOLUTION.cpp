


//////////////////////////////////////////////////////////////////////////
int numTrees(int n) 
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) 
    {
        for (int j = 0; j < i; j++) 
        {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    return dp[n];
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n)
{
	return numTrees(n);
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
	return "../../problems/unique-binary-search-trees/tests.txt";
}

