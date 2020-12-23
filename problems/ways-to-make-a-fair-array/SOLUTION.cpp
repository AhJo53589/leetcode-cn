
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        vector<int> frt(nums.size(), 0);
        vector<int> bck(nums.size(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            frt[i] = (i == 0) ? sum : sum - frt[i - 1];
            // cout << frt[i] << ", ";
        }
        // cout << endl;
        sum = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            sum += nums[i];
            bck[i] = (i == nums.size() - 1) ? sum : sum - bck[i + 1];
            // cout << bck[i] << ", ";
        }
        // cout << endl;
        
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int f_0 = (i % 2 == 0) ? i - 2 : i - 1;
            int f_1 = (i % 2 == 0) ? i - 1 : i - 2;
            int sum_0 = (f_0 < 0) ? 0 : frt[f_0];
            int sum_1 = (f_1 < 0) ? 0 : frt[f_1];
            
            int b_0 = (i % 2 == 0) ? i + 1 : i + 2;
            int b_1 = (i % 2 == 0) ? i + 2 : i + 1;
            sum_0 += (b_0 > nums.size() - 1) ? 0 : bck[b_0];
            sum_1 += (b_1 > nums.size() - 1) ? 0 : bck[b_1];
            
            // cout << sum_0 << ", " << sum_1 << endl;
            ans += (sum_0 == sum_1);
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
	return sln.waysToMakeFair(nums);
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
