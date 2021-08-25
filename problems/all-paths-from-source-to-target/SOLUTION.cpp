
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path = {0};
        dfs(graph, path, 0);
        return ans;
    }

    void dfs(vector<vector<int>>& graph, vector<int>& path, int cur) {
        if (cur == (int)graph.size() - 1) {
            ans.push_back(path);
            return;
        }

        for (auto& next : graph[cur]) {
            path.push_back(next);
            dfs(graph, path, next);
            path.pop_back();
        }
    }

private:
    vector<vector<int>> ans;
};

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<vector<int>>& graph)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.allPathsSourceTarget(graph);
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
