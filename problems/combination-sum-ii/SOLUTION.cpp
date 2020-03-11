//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void dfs(int start, int target) 
    {
        if (target == 0) 
        {
            res.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++) 
        {
            if (i > start&& candidates[i] == candidates[i - 1]) continue;
            path.push_back(candidates[i]);
            // 元素不可重复利用，使用下一个即i+1
            dfs(i + 1, target - candidates[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        dfs(0, target);
        return res;
    }

private:
    vector<int> candidates;
    vector<vector<int>> res;
    vector<int> path;
};

//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
    void dfs(vector<int>& candidates, int target, int idx, vector<int>& cur, vector<vector<int>>& ans)
    {
        if (target == 0)
        {
            ans.push_back(cur);
            return;
        }
        if (idx >= candidates.size()) return;

        int step = 1;
        for (int i = idx + 1; i < candidates.size(); i++)
        {
            step += (candidates[idx] == candidates[i]);
        }
        dfs(candidates, target, idx + step, cur, ans); // k == 0
        for (int k = 1; k <= target / candidates[idx] && k <= step; k++)
        {
            cur.push_back(candidates[idx]);
            dfs(candidates, target - k * candidates[idx], idx + step, cur, ans);
        }
        for (int k = 1; k <= target / candidates[idx] && k <= step; k++)
        {
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
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

    Solution2 sln;
    return sln.combinationSum2(candidates, target);
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

#define USE_CHECKANSWER_CUSTOM
void _checkAnswer_custom(vector<vector<int>>& ans, TestCases& tc)
{
    _checkAnswer_custom_sort(ans, tc);
}