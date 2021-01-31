
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_set<int> cnt;
        unordered_map<int, unordered_set<int>> dic;
        for (int i = 0; i < adjacentPairs.size(); i++) {
            for (int t = 0; t < 2; t++) {
                int a = adjacentPairs[i][t];
                int b = adjacentPairs[i][(t + 1) % 2];
                dic[a].insert(b);
                if (cnt.find(a) == cnt.end()) {
                    cnt.insert(a);
                }
                else {
                    cnt.erase(a);
                }
            }
        }

        vector<int> ans(dic.size());
        ans.front() = *cnt.begin();
        for (int i = 1; i < ans.size(); i++) {
            ans[i] = *(dic[ans[i - 1]].begin());
            dic[ans[i]].erase(ans[i - 1]);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<vector<int>>& adjacentPairs)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.restoreArray(adjacentPairs);
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
