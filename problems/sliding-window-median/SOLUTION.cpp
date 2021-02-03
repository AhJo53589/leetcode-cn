
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans(nums.size() - k + 1);
        multiset<double> window;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k) {
                window.erase(window.find(nums[i - k]));
            }
            window.insert(nums[i]);

            if (i < k - 1) continue;
            auto mid = window.begin();
            std::advance(mid, k / 2);
            ans[i - (k - 1)] = (*mid + *std::prev(mid, (1 - k % 2))) / 2;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<double> _solution_run(vector<int>& nums, int k)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.medianSlidingWindow(nums, k);
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
