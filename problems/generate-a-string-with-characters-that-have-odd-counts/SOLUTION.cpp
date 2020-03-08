
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string generateTheString(int n) 
	{
		string ans = (n % 2 == 0) ? "a" : "";
		n -= (n % 2 == 0);
		for (int i = 0; i < n; i++)
		{
			ans += "b";
		}
		return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(int n)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.generateTheString(n);
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
