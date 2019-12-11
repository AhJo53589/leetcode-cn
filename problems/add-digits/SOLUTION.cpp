


//////////////////////////////////////////////////////////////////////////
int addDigits(int num) 
{
    if (num == 0) return 0;
    return num % 9 ? num % 9 : 9;
}


//////////////////////////////////////////////////////////////////////////
int _solution_run(int num)
{
	return addDigits(num);
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
	return "../../problems/add-digits/tests.txt";
}

