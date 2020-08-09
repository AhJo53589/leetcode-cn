
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0, end = -1;
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (mp.find(sum - target) != mp.end()) {
                if (mp[sum - target] + 1 > end) {
                    ret++;
                    end = i;
                }
            }
            mp[sum] = i;
        }
        return ret;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums, int target)
{
    int caseNo = -1;
    static int caseCnt = 0;
    if (caseNo != -1 && caseCnt++ != caseNo) return {};

	//printVectorT(nums);
	//cout << target << endl;
	Solution sln;
	return sln.maxNonOverlapping(nums, target);
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
