
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.rbegin(), nums.rend(), [](string& a, string& b) {
            return (a.size() != b.size()) ? a.size() < b.size() : a < b;
        });

        return nums[k - 1];
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(vector<string>& nums, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.kthLargestNumber(nums, k);
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
