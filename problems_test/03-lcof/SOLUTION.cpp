
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> us;
        for (auto n : nums) {
            if (us.count(n) != 0) return n;
            us.insert(n);
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
	return sln.findRepeatNumber(nums);
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
