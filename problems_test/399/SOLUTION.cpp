struct DSU
{
    DSU(int n) : data(n, -1) {}

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

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int getIdx(string s, unordered_map<string, int>& um)
    {
        if (um.find(s) != um.end()) return um[s];
        um[s] = um.size();
        return um[s];
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        unordered_map<string, int> um;
        vector<double> num(10000, 0);
        DSU dsu(num.size());
        for (int i = 0; i < equations.size(); i++)
        {
            int a = getIdx(equations[i][0], um);
            int b = getIdx(equations[i][1], um);
            num[b] = (num[a] == 0 && num[b] == 0) ? 1 : num[b];
            if (num[a] == 0)
            {
                num[a] = values[i] * num[b];
            }
            else
            {
                num[b] = num[a] / values[i];
            }

            dsu.unionSet(a, b);
        }

        vector<double> ans;
        for (auto& q : queries)
        {
            int a = getIdx(q[0], um);
            int b = getIdx(q[1], um);
            if (num[a] == 0 || num[b] == 0)
            {
                ans.push_back(-1.0);
                continue;
            }
            if (!dsu.same(a, b))
            {
                ans.push_back(-1.0);
                continue;
            }
            ans.push_back(num[a] / num[b]);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<double> _solution_run(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.calcEquation(equations, values, queries);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//    return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
