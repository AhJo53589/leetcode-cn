


//////////////////////////////////////////////////////////////////////////
string freqAlphabets(string s)
{
    string ans;
    for (size_t i = s.size() - 1; i < s.size(); i--)
    {
        if (s[i] != '#')
        {
            ans.push_back('a' + (s[i] - '1'));
        }
        else
        {
            string t;
            t += s[i - 2];
            t += s[i - 1];
            int n = stoi(t);
            ans.push_back('a' + n - 1);
            i -= 2;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

//////////////////////////////////////////////////////////////////////////
string _solution_run(string s)
{
	return freqAlphabets(s);
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
	return "../../problems/decrypt-string-from-alphabet-to-integer-mapping/tests.txt";
}

