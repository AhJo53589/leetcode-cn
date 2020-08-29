
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int sum = 0;
        for (int i = 0; i < stoneValue.size(); i++) {
            swap(sum, stoneValue[i]);
            sum += stoneValue[i];
        }
        stoneValue.push_back(sum);

        dp = vector<vector<int>>(stoneValue.size(), vector<int>(stoneValue.size(), -1));
        return dfs(stoneValue, 1, stoneValue.size() - 1);
    }

    int dfs(vector<int>& stoneValue, int left, int right) {
        if (dp[left][right] != -1) return dp[left][right];

        if (left == right) return 0;

        int maxVal = 0;

        if (left + 1 == right) {
            int l = stoneValue[left] - stoneValue[left - 1];
            int r = stoneValue[right] - stoneValue[left];
            maxVal = (l < r) ? l : r;
            dp[left][right] = maxVal;
            return maxVal;
        }

        for (int i = left; i < right; i++) {
            int l = stoneValue[i] - stoneValue[left - 1];
            int r = stoneValue[right] - stoneValue[i];
            if (l <= r) {
                maxVal = max(maxVal, l + dfs(stoneValue, left, i));
            }
            if (l >= r) {
                maxVal = max(maxVal, r + dfs(stoneValue, i + 1, right));
            }
        }
        dp[left][right] = maxVal;
        return maxVal;
    }

private:
    vector<vector<int>> dp;
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& stoneValue)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.stoneGameV(stoneValue);
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
