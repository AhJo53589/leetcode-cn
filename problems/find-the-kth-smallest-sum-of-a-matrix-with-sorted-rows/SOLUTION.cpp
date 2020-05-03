
//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> ans(mat[0]);
        for (int i = 1; i < mat.size(); ++i) {
            multiset<int> st;
            for (int x : ans) {
                for (int y : mat[i]) {
                    st.insert(x + y);
                }
            }
            ans.assign(st.begin(), st.end());
            ans.resize(min(k, (int)ans.size()));
        }
        return ans.back();
    }
};

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int l = 0;
        int r = 0;
        for (int i = 0; i < mat.size(); i++) {
            l += mat[i].front();
            r += mat[i].back();
        }

        int base = l;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int cnt = 1;
            dfs(mat, k, mid, 0, base, cnt);
            if (cnt < k) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        return r;
    }

    void dfs(vector<vector<int>>& mat, int k, int maxSum, int idx, int sum, int& cnt) {
        if (idx == mat.size()) return;
        if (sum > maxSum || cnt > k) return;

        dfs(mat, k, maxSum, idx + 1, sum, cnt);

        for (int j = 1; j < mat[idx].size(); j++) {
            int temp = sum + mat[idx][j] - mat[idx][0];
            if (temp > maxSum) break;
            cnt++;
            dfs(mat, k, maxSum, idx + 1, temp, cnt);
        }
    }
};


//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& mat, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorVectorT(mat);
    cout << k << endl;
    Solution sln;
    return sln.kthSmallest(mat, k);
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
