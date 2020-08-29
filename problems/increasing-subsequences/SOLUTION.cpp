
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(nums, 0, INT_MIN);
        return ans;
    }

    void dfs(vector<int>& nums, int idx, int maxVal) {
        if (idx == nums.size()) {
            if (temp.size() > 1) {
                ans.push_back(temp);
            }
            return;
        }

        if (nums[idx] >= maxVal) {
            temp.push_back(nums[idx]);
            dfs(nums, idx + 1, nums[idx]);
            temp.pop_back();
        }

        if (nums[idx] != maxVal) {
            dfs(nums, idx + 1, maxVal);
        }
    }

private:
    vector<vector<int>> ans;
    vector<int> temp;
};

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<int>& nums)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.findSubsequences(nums);
}

#define USE_CHECKANSWER_CUSTOM
void _checkAnswer_custom(vector<vector<int>>& ans, TestCases& tc)
{
    _checkAnswer_custom_sort(ans, tc);
}