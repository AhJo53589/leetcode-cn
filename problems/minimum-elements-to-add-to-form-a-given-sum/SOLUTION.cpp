
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = 0;
        for (auto n : nums) {
            sum += n;
        }
        long long df = abs(1LL * goal - sum);
        return df / limit + (df % limit != 0);
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums, int limit, int goal)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.minElements(nums, limit, goal);
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
