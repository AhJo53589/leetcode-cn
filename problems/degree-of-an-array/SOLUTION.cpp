
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        vector<vector<int>> cnt(50000);
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            if (cnt[n].empty()) {
                cnt[n] = { 1, 1, i };
            }
            else {
                cnt[n][0]++;
                cnt[n][1] = i - cnt[n][2] + 1;
            }
        }

        sort(cnt.begin(), cnt.end(), [](vector<int>& a, vector<int>& b) {
            if (a.empty() && b.empty()) return false;
            if (a.empty()) return false;
            if (b.empty()) return true;
            return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
        });
        return cnt.front()[1];
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.findShortestSubArray(nums);
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
