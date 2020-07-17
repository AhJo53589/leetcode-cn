
//////////////////////////////////////////////////////////////////////////
class Solution {
private:
    static constexpr int UNCOLORED = 0;
    static constexpr int RED = 1;
    static constexpr int GREEN = 2;
    vector<int> color;
    bool valid;

public:
    void dfs(int node, int c, const vector<vector<int>>& graph) {
        color[node] = c;
        int cNei = (c == RED ? GREEN : RED);
        for (int neighbor : graph[node]) {
            if (color[neighbor] == UNCOLORED) {
                dfs(neighbor, cNei, graph);
                if (!valid) {
                    return;
                }
            }
            else if (color[neighbor] != cNei) {
                valid = false;
                return;
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        valid = true;
        color.assign(n, UNCOLORED);
        for (int i = 0; i < n && valid; ++i) {
            if (color[i] == UNCOLORED) {
                dfs(i, RED, graph);
            }
        }
        return valid;
    }
};


//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<vector<int>>& graph)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.isBipartite(graph);
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
