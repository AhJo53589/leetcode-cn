


//////////////////////////////////////////////////////////////////////////
int minFlips(int a, int b, int c) 
{
	int ans = 0;
	for (int i = 0; i < 32; i++)
	{
		int t = c & (1 << i);
		if (t == 0)
		{
			ans += ((a & (1 << i)) != 0);
			ans += ((b & (1 << i)) != 0);
		}
		else
		{
			ans += ((a & (1 << i)) == 0 && (b & (1 << i)) == 0);
		}
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(int a, int b, int c)
{
	return minFlips(a,b,c);
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
	return "../../problems/_test_0/tests.txt";
}

