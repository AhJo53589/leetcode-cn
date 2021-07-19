
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int ans = 0;
        int front = 0;        
        int x = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0) {
                x += (nums[i] - nums[i - 1]) * (i - front);
            }
            while (x > k) {
                x -= (nums[i] - nums[front]);
                front++;
            }
            ans = max(ans, i - front + 1);
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
