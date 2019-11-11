


//////////////////////////////////////////////////////////////////////////
int hammingDistance(int x, int y)
{
	int n = x ^ y;
	int count = 0;
	while (n != 0)
	{
		count++;
		n = n & (n - 1);
	}
	return count;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(int x, int y)
{
	return hammingDistance(x, y);
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
	return "../../problems/hamming-distance/tests.txt";
}

