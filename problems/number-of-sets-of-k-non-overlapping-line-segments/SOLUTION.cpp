
//////////////////////////////////////////////////////////////////////////
int dp[1001][1001];
int sum[1001][1001];
bool flag = false;
void init() {
    memset(dp, 0, sizeof(dp));
    memset(sum, 0, sizeof(sum));
    dp[0][0] = 1;
    sum[0][0] = 1;
    for (int j = 1; j <= 1000; j++) {
        sum[0][j] = j + 1;
    }
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            dp[i][j] = dp[i][j - 1] + sum[i - 1][j - 1];
            dp[i][j] %= 1000000007;
            sum[i][j] = sum[i][j - 1] + dp[i][j];
            sum[i][j] %= 1000000007;
        }
    }
}

class Solution {
public:
    int numberOfSets(int n, int k) {
        if (!flag) {
            flag = true;
            init();
        }
        return dp[k][n - 1];
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, int k)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	cout << "n = " << n << ", k = " << k << endl;
	Solution sln;
	return sln.numberOfSets(n, k);
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
