
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        vector<bool> dp(s.size(), false);
        dp.front() = true;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '1') continue;
            for (int j = minJump; j <= maxJump && i - j >= 0; j++) {
                if (!dp[i - j]) continue;
                dp[i] = true;
                break;
            }
            if (i > maxJump && !dp[i]) return false;
        }
        return dp.back();
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string s, int minJump, int maxJump)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.canReach(s, minJump, maxJump);
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
