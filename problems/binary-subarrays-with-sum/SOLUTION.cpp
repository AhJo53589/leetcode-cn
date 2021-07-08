
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0;
        unordered_map<int, int> cnt;
        int ans = 0;
        for (auto& num : nums) {
            cnt[sum]++;
            sum += num;
            ans += cnt[sum - goal];
        }
        return ans;
    }
};


//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums, int goal)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.numSubarraysWithSum(nums, goal);
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
