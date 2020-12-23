
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans;
        while (n-- > 0) {
            int t = min(k - n, 26);
            char c = 'a' + t - 1;
            ans += c;
            k -= t;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(int n, int k)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.getSmallestString(n, k);
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
