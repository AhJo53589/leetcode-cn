//////////////////////////////////////////////////////////////////////////
struct DSU
{
    DSU(int n) : data(n, -1) { }

    bool unionSet(int x, int y)
    {
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
    int findCircleNum(vector<vector<int>>& M) 
    {
        int ans = M.size();
        DSU dsu(M.size());
        for (size_t i = 0; i < M.size(); i++)
        {
            for (size_t j = i + 1; j < M.size(); j++)
            {
                if (M[i][j] == 0) continue;
                ans -= dsu.unionSet(i, j);
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int findroot(vector<int>& uf, int x)
{
    return (uf[x] == -1) ? x : (uf[x] = findroot(uf, uf[x]));
}

int findCircleNum(vector<vector<int>>& M)
{
    int ans = M.size();
    vector<int> uf(M.size(), -1);
    for (size_t i = 0; i < M.size(); i++)
    {
        for (size_t j = i + 1; j < M.size(); j++)
        {
            if (M[i][j] == 0) continue;
            int x = findroot(uf, i);
            int y = findroot(uf, j);
            if (x == y) continue;
            uf[y] = x;
            ans--;
        }
    }
    return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& M)
{
    Solution sln;
	return sln.findCircleNum(M);
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

