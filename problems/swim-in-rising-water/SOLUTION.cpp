
//////////////////////////////////////////////////////////////////////////
struct DSU {
    DSU(int n) : data(n, -1), cnt(n) {}

    bool unionSet(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (data[x] > data[y]) {
            swap(x, y);
        }
        data[x] += data[y];
        data[y] = x;
        cnt--;
        return true;
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }

    int size(int x) {
        return -data[root(x)];
    }

    vector<int> data;
    int cnt = 0;
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<int>> seq(grid.size() * grid[0].size());
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                seq[grid[i][j]] = { i, j };
            }
        }

        DSU dsu(seq.size());
        for (int i = 0; i < seq.size(); i++) {
            int x = seq[i][0];
            int y = seq[i][1];
            
            int a = x * grid[0].size() + y;
            for (auto& d : dd) {
                int dx = x + d[0];
                int dy = y + d[1];
                if (dx < 0 || dx >= grid.size()) continue;
                if (dy < 0 || dy >= grid[0].size()) continue;
                if (grid[dx][dy] > i) continue;

                int b = dx * grid[0].size() + dy;
                dsu.unionSet(a, b);
            }
            if (dsu.same(0, seq.size() - 1)) return i;
        }
        return seq.size() - 1;
    }

private:
    vector<vector<int>> dd = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& grid)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.swimInWater(grid);
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
