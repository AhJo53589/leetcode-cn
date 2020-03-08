
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) 
	{
		int ans = 0;
		int cnt = 0;
		int mx = 0;
		for (auto& n : light)
		{
			mx = max(mx, n);
			cnt++;
			ans += (mx == cnt);
		}
		return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& light)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.numTimesAllBlue(light);
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
