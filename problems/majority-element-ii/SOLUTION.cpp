
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<pair<int, int>> vote(2);
        for (auto n : nums) {
            int empty = -1;
            int match = -1;
            for (int i = 0; i < vote.size(); i++) {
                match = (vote[i].first == n && vote[i].second > 0) ? i: match;
                empty = (vote[i].second == 0) ? i : empty;
            }
            if (match != -1) {
                vote[match].second++;
                continue;
            }
            if (empty != -1) {
                vote[empty].first = n;
                vote[empty].second++;
                continue;
            }
            for (int i = 0; i < vote.size(); i++) {
                vote[i].second--;
            }
        }

        vector<int> ans;
        vector<int> cnt(2);
        for (auto n : nums) {
            for (int i = 0; i < vote.size(); i++) {
                cnt[i] += (vote[i].first == n && vote[i].second > 0);
            }
        }
        for (int i = 0; i < cnt.size(); i++) {
            if (cnt[i] > nums.size() / 3) {
                ans.push_back(vote[i].first);
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.majorityElement(nums);
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
