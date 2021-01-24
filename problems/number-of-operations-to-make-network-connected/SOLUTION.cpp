


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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int ans = n;
        DSU dsu(n);
        for (auto& c : connections) {
            ans -= (dsu.unionSet(c[0], c[1]));
        }        
        return connections.size() < n - 1 ? -1 : ans - 1;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, vector<vector<int>>& connections)
{
    Solution sln;
    return sln.makeConnected(n, connections);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

