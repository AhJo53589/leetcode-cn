
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> inDegree(n, 0);
        vector<vector<int>> lst(n, vector<int>());
        vector<unordered_set<int>> vi(n, unordered_set<int>());
        
        for (auto v : prerequisites) {
            inDegree[v[1]]++;
            lst[v[0]].push_back(v[1]);
        }

        queue<int> que;
        for (auto i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] == 0) {
                que.push(i);
            }
        }

        while (!que.empty()) {
            auto q = que.front();
            que.pop();

            for (auto l : lst[q]) {
                for (auto v = vi[q].begin(); v != vi[q].end(); v++) {
                    vi[l].insert(*v);
                }
                vi[l].insert(q);

                if (--inDegree[l] == 0) {
                    que.push(l);
                }
            }
        }

        vector<bool> ans(queries.size(), false);
        for (int i = 0; i < queries.size(); i++) {
            ans[i] = (vi[queries[i][1]].count(queries[i][0]) != 0);
        }

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<bool> _solution_run(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << n << endl;
    printVectorVectorT(prerequisites);
    printVectorVectorT(queries);
    cout << endl;
    Solution sln;
    return sln.checkIfPrerequisite(n, prerequisites, queries);
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
