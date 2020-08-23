
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
    int findLatestStep(vector<int>& arr, int m) {
        int ans = -1;
        DSU dsu(arr.size());
        vector<bool> vi(arr.size(), false);
        int lenM = 0;
        for (int j = 0; j < arr.size(); j++) {
            int i = arr[j] - 1;
            vi[i] = true;
            if (i != 0 && vi[i - 1]) {
                lenM -= (m == dsu.size(i - 1));
                dsu.unionSet(i - 1, i);
            }
            if (i != arr.size() - 1 && vi[i + 1]) {
                lenM -= (m == dsu.size(i + 1));
                dsu.unionSet(i + 1, i);
            }
            lenM += (m == dsu.size(i));
            ans = (lenM != 0) ? j + 1 : ans;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& arr, int m)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(arr);
    cout << m << endl;
    Solution sln;
    return sln.findLatestStep(arr, m);
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
