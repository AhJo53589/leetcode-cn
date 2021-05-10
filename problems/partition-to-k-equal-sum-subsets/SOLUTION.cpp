
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        int avg = sum / k;

        vector<int> vi(nums.size(), 0);
        return dfs(nums, vi, avg, 0, k);
    }

    bool dfs(vector<int>& nums, vector<int>& vi, int target, int sum, int k) {
        if (k == 0) return true;

        int firstIdx = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (vi[i] == 1) continue;
            firstIdx = (firstIdx == -1) ? i : firstIdx;
            if (sum == 0 && i != firstIdx) return false;

            int temp = sum + nums[i];
            if (temp > target) continue;

            int nextK = (temp == target) ? k - 1 : k;
            int nextSum = (temp == target) ? 0 : temp;

            vi[i] = 1;
            if (dfs(nums, vi, target, nextSum, nextK)) return true;
            vi[i] = 0;
        }
        return false;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& nums, int k)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.canPartitionKSubsets(nums, k);
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
