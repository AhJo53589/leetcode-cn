
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        nums.push_back(0);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] < i) break;
            if (nums[i] < i) return i;
        }
        return -1;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.specialArray(nums);
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
