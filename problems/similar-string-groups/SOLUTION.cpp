
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
    int numSimilarGroups(vector<string>& strs) {
        DSU dsu(strs.size());
        for (int i = 0; i < strs.size(); i++) {
            for (int j = i + 1; j < strs.size(); j++) {
                if (dsu.same(i, j)) continue;
                if (!check(strs[i], strs[j])) continue;
                dsu.unionSet(i, j);
            }
        }
        return dsu.cnt;
    }

    bool check(string& s1, string& s2) {
        int dif = 0;
        for (int i = 0; i < s1.size(); i++) {
            dif += (s1[i] != s2[i]);
        }
        return (dif == 0 || dif == 2);
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<string>& strs)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.numSimilarGroups(strs);
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
