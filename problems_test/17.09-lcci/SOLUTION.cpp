
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int getKthMagicNumber(int k) {
        if (k <= 0) return 0;

        vector<long long int> nums(k + 1, 1);
        int p3 = 0;
        int p5 = 0;
        int p7 = 0;
        for (int i = 1; i < k; ++i) {
            nums[i] = min(min(3 * nums[p3], 5 * nums[p5]), 7 * nums[p7]);
            p3 += (nums[i] == 3 * nums[p3]);
            p5 += (nums[i] == 5 * nums[p5]);
            p7 += (nums[i] == 7 * nums[p7]);
        }
        return nums[k - 1];
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int k)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.getKthMagicNumber(k);
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
