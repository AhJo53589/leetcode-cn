
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
		int zeroLeft = -1;
		int zeroRight = -1;
		int ans = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 0) {
				if (zeroLeft == -1 && zeroRight == -1) {
					zeroLeft = i;
				}
				else if (zeroLeft != -1 && zeroRight == -1) {
					zeroRight = i;
				}
				else {
					zeroLeft = zeroRight;
					zeroRight = i;
				}
			}
			
			int len = 0;
			if (zeroLeft == -1 && zeroRight == -1) {
				len = i;
			}
            else if (zeroLeft != -1 && zeroRight == -1) {
				len = i;
            }
            else {
				len = i - zeroLeft - 1;
            }

			ans = max(ans, len);
		}
		return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.longestSubarray(nums);
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
