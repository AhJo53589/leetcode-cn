
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int translateNum(int num) {
        vector<int> dp(3, 1);
        int i = 1;
        int mod = 0;
        while (num >= 10) {
            i++;
            mod = num % 100;
            num /= 10;
            if (mod < 26 && mod > 9) {
                dp[i % 3] = dp[(i + 2) % 3] + dp[(i + 1) % 3];
            }
            else {
                dp[i % 3] = dp[(i + 2) % 3];
            }
        }
        return dp[i % 3];
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int num)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.translateNum(num);
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
