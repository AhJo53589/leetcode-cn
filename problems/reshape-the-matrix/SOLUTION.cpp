
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (r * c != nums.size() * nums[0].size()) return nums;

        vector<vector<int>> ans(r, vector<int>(c, 0));
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[0].size(); j++) {
                int idx = i * nums[0].size() + j;
                int di = idx / c;
                int dj = idx % c;
                ans[di][dj] = nums[i][j];
            }
        }

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<vector<int>>& nums, int r, int c)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.matrixReshape(nums, r, c);
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
