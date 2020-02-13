


//////////////////////////////////////////////////////////////////////////
int maximum69Number (int num) {
    string n = to_string(num);
    for (size_t i = 0; i < n.size(); i++)
    {
        if (n[i] == '9') continue;
        n[i] = '9';
        break;
    }
    return stoi(n);
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(int num)
{
	return maximum69Number(num);
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

