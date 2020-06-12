
//////////////////////////////////////////////////////////////////////////
struct DSU {
    std::vector<int> data;

    void init(int n) { data.assign(n, -1); }

    bool unionSet(int x, int y) {
        x = root(x);
        y = root(y);
        if (x != y) {
            if (data[y] < data[x]) {
                std::swap(x, y);
            }
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }

    bool same(int x, int y) { return root(x) == root(y); }

    int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }

    int size(int x) { return -data[root(x)]; }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU dsu;
        dsu.init(26);

        for (auto& e : equations) {
            if (e[1] == '!') continue;
            dsu.unionSet((int)(e[0] - 'a'), (int)(e[3] - 'a'));
        }

        for (auto& e : equations) {
            if (e[1] != '!') continue;
            if (dsu.same(e[0] - 'a', e[3] - 'a')) return false;
        }

        return true;
    }
};


//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<string>& equations)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.equationsPossible(equations);
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
