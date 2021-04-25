
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());

        vector<long long> dif(nums.size(), 0);
        for (int i = 1; i < nums.size(); i++) {
            dif[i] = nums[0] - nums[i];
            dif[i] += dif[i - 1];
        }

        int ans = 0;
        int i = 0;
        int j = 0;
        while (i < nums.size()) {
            while (j < nums.size()) {
                if (dif[j] - dif[i] - (1LL * (nums[0] - nums[i]) * (j - i)) > k) break;
                j++;
            }
            ans = max(ans, j - i);
            i++;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    //printVectorT(nums);
    //cout << k << endl;

    Solution sln;
    return sln.maxFrequency(nums, k);
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
