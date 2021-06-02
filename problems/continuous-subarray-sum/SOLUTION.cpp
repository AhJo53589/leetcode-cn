
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> dic;
        dic[0] = -1;
        for (int i = 0, s = 0; i < nums.size(); i++) {
            s += nums[i];
            s %= k;
            if (dic.find(s) != dic.end()) {
                if (i - dic[s] > 1) return true;
            } 
            else {
                dic[s] = i;
            }
        }
        return false;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& nums, int k)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.checkSubarraySum(nums, k);
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
