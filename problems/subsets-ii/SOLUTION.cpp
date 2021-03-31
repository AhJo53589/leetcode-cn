
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ans;
    }

    void dfs(vector<int>& nums, int index) {
        ans.push_back(temp);

        for (int i = index; i < nums.size(); i++) {
            if (i != index && nums[i] == nums[i - 1]) continue;

            temp.push_back(nums[i]);
            dfs(nums, i + 1);
            temp.pop_back();
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
	return sln.subsetsWithDup(nums);
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
