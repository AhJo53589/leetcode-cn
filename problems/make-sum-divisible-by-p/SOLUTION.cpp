
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
		int ans = INT_MAX;
		unordered_map<int, int> mp;
		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			mp[p - sum % p] = i;
		}
		sum = 0;
		for (int i = nums.size() - 1; i >= 0; i--) {
			sum += nums[i];
			if (mp.count(sum % p)) {
				if (i < mp[sum % p]) continue;
				ans = min(ans, i - mp[sum % p]);
			}
		}
		return ans == INT_MAX ? -1 : ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums, int p)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.minSubarray(nums, p);
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
