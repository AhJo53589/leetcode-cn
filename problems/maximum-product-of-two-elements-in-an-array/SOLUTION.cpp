
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a = nums[0];
        int b = nums[1];
        if (a < b) {
            swap(a, b);
        }

        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] >= a) {
                b = a;
                a = nums[i];
            }
            else if (nums[i] >= b) {
                b = nums[i];
            }
        }

        return (a - 1) * (b - 1);
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.maxProduct(nums);
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
