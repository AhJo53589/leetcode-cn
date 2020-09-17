
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        data = vector<int>(edges.size() + 1, -1);
        for (auto e : edges) {
            if (root(e[0]) != -1 && root(e[0]) == root(e[1])) return e;
            join(e[0], e[1]);
        }
        return {};
    }

    bool same(int x, int y) {
        return (root(x) == root(y));
    }

    int root(int x) {
        return (data[x] < 0) ? x : data[x] = root(data[x]);
    }

    void join(int x, int y) {
        if (same(x, y)) return;
        x = root(x);
        y = root(y);
        data[x] += data[y];
        data[y] = x;  
    }

private:
    vector<int> data;
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<vector<int>>& edges)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.findRedundantConnection(edges);
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
