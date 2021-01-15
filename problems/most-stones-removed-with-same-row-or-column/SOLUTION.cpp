
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
    int removeStones(vector<vector<int>>& stones) {
        int ans = 0;
        DSU dsu(stones.size());
        unordered_map<int, int> row;
        unordered_map<int, int> col;

        for (int i = 0; i < stones.size(); i++) {
            int x = stones[i][0];
            int y = stones[i][1];
            if (row.find(x) != row.end()) {
                ans += dsu.unionSet(i, row[x]);
            }
            row[x] = i;
            if (col.find(y) != col.end()) {
                ans += dsu.unionSet(i, col[y]);
            }
            col[y] = i;
        }

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(int x, int y)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.unionSet(x, y);
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
