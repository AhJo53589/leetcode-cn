
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findTheLongestSubstring(string s) 
	{
		vector<char> vowel = { 'a', 'e', 'i', 'o', 'u' };
		map<char, int> count;
		for (auto&c : s)
		{
			count[c]++;
		}
		map<char, int> window;
		for (auto& c : vowel)
		{
			if ()
			{
			}
		}
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.findTheLongestSubstring(s);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
