
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        for (auto& ed : edges) {
            indegree[ed[1]]++;
        }
        vector<int> ans;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(int n, vector<vector<int>>& edges)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.findSmallestSetOfVertices(n, edges);
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
