
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string compressString(string s) 
	{
		if (s.empty()) return s;
		string ans = { s[0] };
		int cnt = 0;
		for (int i = 1; i <= s.size(); i++)
		{
            cnt++;
			if (i == s.size() || s[i] != ans.back())
			{
				ans += to_string(cnt);
				if (i == s.size()) continue;
                ans += s[i];
				cnt = 0;
				continue;
			}
		}
		return s.size() <= ans.size() ? s : ans;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string S)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.compressString(S);
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
