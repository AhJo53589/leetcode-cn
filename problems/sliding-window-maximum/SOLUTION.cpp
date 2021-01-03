
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        nums.push_back(INT_MIN);
        vector<int> ans(nums.size() - k);
        deque<int> dq;

        for (int i = 0; i < nums.size(); i++) {
            if (i >= k) {
                ans[i - k] = nums[dq.front()];
                if (dq.front() == i - k) {
                    dq.pop_front();
                }
            }

            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums, int k)
{
    Solution sln;
    return sln.maxSlidingWindow(nums, k);
}

//#define USE_SOLUTION_CUSTOM
//vector<int> _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}

