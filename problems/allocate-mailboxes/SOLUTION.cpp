
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(), houses.end());

        // dp[邮筒个数][到第几个房子]
        vector<vector<int>> dp(k + 1, vector<int>(houses.size() + 1, 0));

        for (int i = 1; i <= houses.size(); i++) {
            for (int j = 1; j <= min(i, k); j++) {
                for (int temp_i = i - 1; temp_i >= 0; temp_i--) {
                    dp[j][i] = min(dp[j][i], dp[j - 1][temp_i] + getDis(houses, { temp_i + 1, i }));
                }
            }
        }

        return dp[k][houses.size()];
    }

    int getDis(vector<int>& houses, vector<int> idx) {
        if (idx[0] >= houses.size() || idx[1] >= houses.size()) return 0;
        if (cache.count(idx) != 0) return cache[idx];

        if (idx[1] - idx[0] <= 2) {
            cache[idx] = houses[idx[1]] - houses[idx[0]];
        }
        else {
            cache[idx] = houses[idx[1]] - houses[idx[0]] + getDis(houses, { idx[0] + 1, idx[1] - 1 });
        }
        return cache[idx];
    }

private:
    map<vector<int>, int> cache;
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& houses, int k)
{
    int caseNo = 0;
    static int caseCnt = 0;
    if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(houses, 12);
    sort(houses.begin(), houses.end());
    printVectorT(houses, 12);
    cout << k << endl;

    Solution sln;
    return sln.minDistance(houses, k);
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
