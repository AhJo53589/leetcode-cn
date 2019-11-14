


//////////////////////////////////////////////////////////////////////////
string convert(string s, int numRows)
{
	if (numRows == 1) return s;
	string ans;
	size_t iStep = numRows * 2 - 2;
	for (size_t i = 0; i < numRows; i++)
	{
		size_t iOffset = (i == 0) ? 0 : (numRows - i - 1) * 2;
		size_t t = i;
		while (t < s.size())
		{
			ans.push_back(s[t]);
			if (iOffset != 0 && t + iOffset < s.size())
			{
				ans.push_back(s[t + iOffset]);
			}
			t += iStep;
		}
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
string _solution_run(string s, int numRows)
{
	return convert(s,numRows);
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
	return "../../problems/zigzag-conversion/tests.txt";
}

