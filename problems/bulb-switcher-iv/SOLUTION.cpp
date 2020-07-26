
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minFlips(string target) {
        int ans = 0;
        int cur = 0;
        for (int i = 0; i < target.size(); i++) {
            if (target[i] == '0' + cur) continue;
            cur = (cur + 1) % 2;
            ans++;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string target)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << target << endl;
    Solution sln;
    return sln.minFlips(target);
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
