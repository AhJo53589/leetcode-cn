
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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.rbegin(), edges.rend());
        int ans = 0;
        int ans_type3 = 0;
        for (int t = 1; t <= 2; t++) {
            DSU dsu(n);
            int cnt_12 = 0;
            int cnt_3 = 0;
            for (int i = 0; i < edges.size(); i++) {
                if (edges[i][0] == t) continue;
                if (!dsu.unionSet(edges[i][1] - 1, edges[i][2] - 1)) {
                    cnt_12 += (edges[i][0] != 3);
                    cnt_3 += (edges[i][0] == 3);
                }
            }
            if (dsu.cnt != 1) return -1;
            ans += cnt_12;
            ans_type3 = cnt_3;
        }
        return ans + ans_type3;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, vector<vector<int>>& edges)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.maxNumEdgesToRemove(n, edges);
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
