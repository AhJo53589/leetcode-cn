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

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for (int i = 0; i < m; ++i) {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](const auto& u, const auto& v) {
            return u[2] < v[2];
        });

        // ¼ÆËã value
        DSU uf_std(n);
        int value = 0;
        for (int i = 0; i < m; ++i) {
            if (uf_std.unionSet(edges[i][0], edges[i][1])) {
                value += edges[i][2];
            }
        }

        vector<vector<int>> ans(2);

        for (int i = 0; i < m; ++i) {
            // ÅÐ¶ÏÊÇ·ñÊÇ¹Ø¼ü±ß
            DSU uf(n);
            int v = 0;
            for (int j = 0; j < m; ++j) {
                if (i != j && uf.unionSet(edges[j][0], edges[j][1])) {
                    v += edges[j][2];
                }
            }
            if (uf.cnt != 1 || (uf.cnt == 1 && v > value)) {
                ans[0].push_back(edges[i][3]);
                continue;
            }

            // ÅÐ¶ÏÊÇ·ñÊÇÎ±¹Ø¼ü±ß
            uf = DSU(n);
            uf.unionSet(edges[i][0], edges[i][1]);
            v = edges[i][2];
            for (int j = 0; j < m; ++j) {
                if (i != j && uf.unionSet(edges[j][0], edges[j][1])) {
                    v += edges[j][2];
                }
            }
            if (v == value) {
                ans[1].push_back(edges[i][3]);
            }
        }

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(int n, vector<vector<int>>& edges)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.findCriticalAndPseudoCriticalEdges(n, edges);
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
