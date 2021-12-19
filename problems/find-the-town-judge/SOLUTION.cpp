
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> cnt(n, 0);
        unordered_set<int> judge;
        for (int i = 0; i < n; i++) {
            judge.insert(i);
        }

        for (auto& t : trust) {
            judge.erase(t[0] - 1);
            cnt[t[1] - 1]++;
        }

        if (judge.size() == 1) {
            auto it = judge.begin();
            int x = *it;
            if (cnt[x] == n - 1) return x + 1;
        }
        return -1;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, vector<vector<int>>& trust)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.findJudge(n, trust);
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
