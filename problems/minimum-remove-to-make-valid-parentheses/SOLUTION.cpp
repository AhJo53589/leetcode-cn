
//////////////////////////////////////////////////////////////////////////
string valid(string s, char da, char db)
{
    int a = 0;
    string ans;
    for (auto c : s)
    {
        if (c == da)
        {
            a++;
        }
        else if (c == db)
        {
            if (a == 0) continue;
            a--;
        }
        ans += c;
    }

    return ans;
}

string minRemoveToMakeValid(string s) 
{
    s = valid(s, '(', ')');
    reverse(s.begin(), s.end());
    s = valid(s, ')', '(');
    reverse(s.begin(), s.end());
    return s;
}

//////////////////////////////////////////////////////////////////////////
string _solution_run(string s)
{
	return minRemoveToMakeValid(s);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
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
	return "../../problems/minimum-remove-to-make-valid-parentheses/tests.txt";
}

