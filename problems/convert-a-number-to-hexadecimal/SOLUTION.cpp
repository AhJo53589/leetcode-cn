
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        long long lnum = (num < 0) ? (long long)pow(2, 32) + num : num;
        string ans = "";
        while (lnum > 0) {
            int x = lnum % 16;
            lnum /= 16;
            ans += (x < 10) ? '0' + x : 'a' + x - 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(int num)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.toHex(num);
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
