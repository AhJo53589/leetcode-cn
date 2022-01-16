
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans = 0;
        while (target != 1 && maxDoubles > 0) {
            ans += target % 2;
            target /= 2;
            maxDoubles--;
            ans++;
        }
        ans += target - 1;
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int target, int maxDoubles)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.minMoves(target, maxDoubles);
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
