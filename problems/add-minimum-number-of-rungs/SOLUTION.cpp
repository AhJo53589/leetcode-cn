
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        rungs.insert(rungs.begin(), 0);
        int ans = 0;
        for (int i = 0; i + 1 < rungs.size(); i++) {
            if (rungs[i] + dist >= rungs[i + 1]) continue;
            int t = rungs[i + 1] - rungs[i];
            ans += t / dist - (t % dist == 0);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& rungs, int dist)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.addRungs(rungs, dist);
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
