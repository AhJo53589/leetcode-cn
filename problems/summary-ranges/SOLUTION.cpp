
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        nums.push_back(INT_MIN);
        vector<string> ans;
        int left = 0; 
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && 1LL * nums[i] != 1LL * nums[i - 1] + 1) {
                if (left == i - 1) {
                    ans.push_back(to_string(nums[i - 1]));
                }
                else {
                    ans.push_back(to_string(nums[left]) + "->" + to_string(nums[i - 1]));
                }
                left = i;
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<string> _solution_run(vector<int>& nums)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.summaryRanges(nums);
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
