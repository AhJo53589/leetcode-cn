
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> sum(maxVal + 2, 0);
        for (auto& n : nums) {
            sum[n] += n;
        }

        int first = 0;
        int second = sum[1];
        for (int i = 2; i < sum.size(); i++) {
            int temp = max(second, first + sum[i]);
            first = second;
            second = temp;
        }
        return second;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.deleteAndEarn(nums);
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
