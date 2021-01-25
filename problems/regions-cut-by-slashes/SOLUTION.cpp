
//////////////////////////////////////////////////////////////////////////
struct DSU {
    DSU(int n) : data(n, -1) {}

    bool unionSet(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;

        if (data[y] < data[x]) std::swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    bool same(int x, int y) { return root(x) == root(y); }

    int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }

    int size(int x) { return -data[root(x)]; }

    std::vector<int> data;
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int ans = grid.size() * grid[0].size() * 4;
        DSU dsu(ans);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                int a = (i * grid[i].size() + j) * 4;
                if (grid[i][j] != '\\') {
                    ans -= dsu.unionSet(a + 0, a + 3);
                    ans -= dsu.unionSet(a + 1, a + 2);
                }
                if (grid[i][j] != '/') {
                    ans -= dsu.unionSet(a + 0, a + 1);
                    ans -= dsu.unionSet(a + 2, a + 3);
                }

                if (i != 0) {
                    int b = ((i - 1) * grid[0].size() + j) * 4;
                    ans -= dsu.unionSet(a + 0, b + 2);
                }
                if (j != 0) {
                    int b = (i * grid[0].size() + (j - 1)) * 4;
                    ans -= dsu.unionSet(a + 3, b + 1);
                }
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<string>& grid)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.regionsBySlashes(grid);
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
