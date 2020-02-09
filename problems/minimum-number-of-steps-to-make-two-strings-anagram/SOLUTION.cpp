
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minSteps(string s, string t) 
	{
		vector<int> char_s(26, 0);
		vector<int> char_t(26, 0);
		for (auto c : s)
		{
			char_s[c - 'a']++;
		}
		for (auto c : t)
		{
			char_t[c - 'a']++;
		}
		int ans = 0;
		for (int i = 0; i < 26; i++)
		{
			ans += (char_s[i] > char_t[i]) ? char_s[i] - char_t[i] : 0;
		}
		return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s, string t)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.minSteps(s, t);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
