
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        vector<int> t(26, 0);
        t[keysPressed[0] - 'a'] = releaseTimes[0];
        for (int i = 1; i < releaseTimes.size(); i++) {
            t[keysPressed[i] - 'a'] = max(t[keysPressed[i] - 'a'], releaseTimes[i] - releaseTimes[i - 1]);
        }

        char ans = keysPressed[0];
        int maxT = 0;
        for (int i = 0; i < t.size(); i++) {
            if (t[i] >= maxT) {
                maxT = t[i];
                ans = 'a' + i;
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
char _solution_run(vector<int>& releaseTimes, string keysPressed)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.slowestKey(releaseTimes, keysPressed);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//    return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
