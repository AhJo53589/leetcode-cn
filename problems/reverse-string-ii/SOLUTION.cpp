
void swapStr(string &s, size_t bg, size_t ed)
{
    if (bg >= s.size()) return;
    if (ed >= s.size()) 
    {
        ed = s.size() - 1;
    }
    while (bg < ed)
    {
        swap(s[bg++], s[ed--]);
    }
}

//////////////////////////////////////////////////////////////////////////
string reverseStr(string s, int k)
{
    for (int i = 0; i < s.size(); i += k * 2)
    {
        swapStr(s, i, i + k - 1);
    }
    return s;
}

//////////////////////////////////////////////////////////////////////////
string _solution_run(string s, int k)
{
	return reverseStr(s,k);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

