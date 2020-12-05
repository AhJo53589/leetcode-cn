
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> cnt;
        unordered_map<int, int> seq;
        for (auto n : nums) {
            cnt[n]++;
        }

        for (auto n : nums) {
            if (cnt[n] == 0) continue;

            cnt[n]--;
            if (seq[n - 1] != 0) {
                seq[n - 1]--;
                seq[n]++;
                continue;
            }
            if (cnt[n + 1] != 0 && cnt[n + 2] != 0) {
                cnt[n + 1]--;
                cnt[n + 2]--;
                seq[n + 2]++;
                continue;
            }
            return false;
        }
        return true;
    }
};


//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& nums)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.isPossible(nums);
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
