
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        ans = vector<vector<int>>(rowSum.size(), vector<int>(colSum.size(), 0));
        vi = vector<vector<bool>>(rowSum.size(), vector<bool>(colSum.size(), false));
        
        dfs(rowSum, colSum, 0, 0);
        return ans;
    }
    
    bool dfs(vector<int>& rowSum, vector<int>& colSum, int r, int c) {
        if (r >= ans.size() || c >= ans[0].size()) return true;
        if (vi[r][c]) return true;
        
        vi[r][c] = true;
        for (int i = min(rowSum[r], colSum[c]); i >= 0; i--) {
            ans[r][c] = i;
            rowSum[r] -= i;
            colSum[c] -= i;
            if (dfs(rowSum, colSum, r + 1, c) && dfs(rowSum, colSum, r, c + 1)) return true;
            rowSum[r] += i;
            colSum[c] += i;
        }
        vi[r][c] = false;
        return false;
    }
    
private:
    vector<vector<int>> ans;
    vector<vector<bool>> vi;
};

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<int>& rowSum, vector<int>& colSum)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.restoreMatrix(rowSum, colSum);
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
