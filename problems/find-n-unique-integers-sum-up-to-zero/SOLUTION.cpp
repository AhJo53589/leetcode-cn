


//////////////////////////////////////////////////////////////////////////
vector<int> sumZero(int n)
{
    vector<int> ans;
    for (int i = 0; i < n / 2; i++)
    {
        ans.push_back(i + 1);
        ans.push_back(- i - 1);
    }
    if (n % 2 == 1)
    {
        ans.push_back(0);
    }
    return ans;
}

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(int n)
{
	return sumZero(n);
}

//#define USE_SOLUTION_CUSTOM
//vector<int> _solution_custom(TestCases &tc)
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
	return "../../problems/find-n-unique-integers-sum-up-to-zero/tests.txt";
}

