


//////////////////////////////////////////////////////////////////////////
int subtractProductAndSum(int n) 
{
    string num = to_string(n);
    int a = 1;
    int b = 0;
    for (auto i = 0; i < num.size(); i++)
    {
        a *= num[i] - '0';
        b += num[i] - '0';
    }
    return a - b;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n)
{
	return subtractProductAndSum(n);
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
	return "../../problems/subtract-the-product-and-sum-of-digits-of-an-integer/tests.txt";
}

