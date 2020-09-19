
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int paintingPlan(int n, int k) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (calc(n, i, j) == k) {
                    ans += cnm(n, i) * cnm(n, j);
                }
            }
        }
        ans += (calc(n, 0, n) == k);
        return ans;
    }

    int calc(int n, int i, int j) {
        return (i + j) * n - i * j;
    }

    int cnm(int n, int m) {
        if (m == 0) return 1;
        if (m == n) return 1;
        if (m > n / 2) return cnm(n, n - m);
        int a = 1;
        for (int i = 0; i < m; i++) a *= (n - i);
        int b = 1;
        for (int i = m; i > 0; i--) b *= i;
        return a / b;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << n << ", " << k << endl;
    Solution sln;
    return sln.paintingPlan(n, k);
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
