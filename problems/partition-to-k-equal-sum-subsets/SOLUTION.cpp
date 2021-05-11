//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        int avg = sum / k;

        vi = vector<bool>(nums.size(), false);
        return dfs(nums, avg, 0, 0, k);
    }

    bool dfs(vector<int>& nums, int target, int sum, int idx, int k) {
        if (k == 0) return true;
        
        for (int i = idx; i < nums.size(); i++) {
            if (vi[i]) continue;
            
            int temp = sum + nums[i];
            if (temp > target) continue;

            int nextSum = (temp == target) ? 0 : temp;
            int nextIdx = (temp == target) ? 0 : idx + 1;
            int nextK = (temp == target) ? k - 1 : k;

            if (i > 0 && nums[i - 1] == nums[i] && !vi[i - 1]) continue;

            vi[i] = true;
            if (dfs(nums, target, nextSum, nextIdx, nextK)) return true;
            vi[i] = false;
        }
        return false;
    }

private:
    vector<bool> vi;
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& nums, int k)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(nums);
    cout << k << endl;
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
