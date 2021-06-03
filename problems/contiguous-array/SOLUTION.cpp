
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> um;
        um[0] = -1;

        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt += (nums[i] == 0) ? -1 : 1;
            if (um.find(cnt) != um.end()) {
                ans = max(ans, i - um[cnt]);
                continue;
            }
            um[cnt] = i;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.findMaxLength(nums);
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
