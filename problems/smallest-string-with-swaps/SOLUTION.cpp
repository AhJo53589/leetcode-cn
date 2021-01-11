
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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        DSU dsu(s.size());
        for (auto p : pairs) {
            dsu.unionSet(p[0], p[1]);
        }

        unordered_map<int, vector<char>> um;
        for (int i = 0; i < s.size(); i++) {
            um[dsu.root(i)].push_back(s[i]);
        }
        for (auto& [i, v] : um) {
            sort(v.rbegin(), v.rend());
        }

        for (int i = 0; i < s.size(); i++) {
            s[i] = um[dsu.root(i)].back();
            um[dsu.root(i)].pop_back();
        }
        return s;
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
