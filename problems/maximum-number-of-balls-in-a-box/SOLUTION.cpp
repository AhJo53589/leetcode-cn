
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int ans = 0;
        unordered_map<int, int> cnt;
        for (int i = lowLimit; i <= highLimit; i++) {
            int t = i;
            int x = 0;
            while (t != 0) {
                x += t % 10;
                t /= 10;
            }
            cnt[x]++;
            ans = max(ans, cnt[x]);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int lowLimit, int highLimit)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.countBalls(lowLimit, highLimit);
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
