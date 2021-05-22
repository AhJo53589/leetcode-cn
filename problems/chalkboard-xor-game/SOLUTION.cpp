
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool xorGame(vector<int>& nums) {
        return !(nums.size() & 1) || 
        !accumulate(nums.begin(), nums.end(), 0, bit_xor{});
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& nums)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.xorGame(nums);
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
