
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void dfs(vector<int>& candidates, int target, int idx, vector<int>& cur, vector<vector<int>>& ans)
    {
        if (target == 0)
        {
            ans.push_back(cur);
            return;
        }
        if (idx >= candidates.size()) return;
        if (target < 0) return;

        dfs(candidates, target, idx + 1, cur, ans); // k == 0
        for (int k = 1; k <= target / candidates[idx]; k++)
        {
            cur.push_back(candidates[idx]);
            dfs(candidates, target - k * candidates[idx], idx + 1, cur, ans);
        }
        for (int k = 1; k <= target / candidates[idx]; k++)
        {
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(candidates, target, 0, cur, ans);
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<int>& candidates, int target)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.combinationSum(candidates, target);
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

#define USE_CHECKANSWER_CUSTOM
void _checkAnswer_custom(vector<vector<int>>& ans, TestCases& tc)
{
	_checkAnswer_custom_sort(ans, tc);
}