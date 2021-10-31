
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> mp;
        for (auto& n : nums) {
            if (mp.find(n) == mp.end()) {
                mp.insert(n);
            }
            else {
                mp.erase(n);
            }
        }
        return vector<int>(mp.begin(), mp.end());
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.singleNumber(nums);
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
