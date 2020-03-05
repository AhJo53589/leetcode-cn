
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        perm = vector<int>(nums.size(), 0);
        vi = vector<bool>(nums.size(), false);
        dfs(nums, 0);
        return ans;
    }

    void dfs(vector<int>& nums, int depth)
    {
        if (depth == nums.size())
        {
            ans.push_back(perm);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (vi[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !vi[i - 1]) continue;

            vi[i] = true;
            perm[depth] = nums[i];
            dfs(nums, depth + 1);
            vi[i] = false;
        }
    }

private:
    vector<int> perm;
    vector<bool> vi;
    vector<vector<int>> ans;
};
//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<int>& nums)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.permuteUnique(nums);
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
