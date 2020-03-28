
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) 
    {
        vector<int> nums = {0};
        partial_sum(A.begin(), A.end(), back_inserter(nums));
        
        vector<int> st;
        for (int i = 0; i < nums.size(); i++)
        {
            while (!st.empty() && st.back() > nums[i])
            {
                st.pop_back();
            }
            if ((st.size() == 1 && nums[st.back()] == nums[i]) 
                || (st.size() > 1 && nums[st[st.size() - 2]] == nums[st.back()] && nums[st.back()] == nums[i]))
            {
                st.pop_back();
            }
            st.push_back(i);
        }

        if (st.empty()) return -1;
        int ans = nums[st.front()] >= K ? st.front() : INT_MAX;
        int l = 0;
        int r = 0;
        while (r < st.size())
        {
            int sum = nums[st[r]] - 
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& A, int K)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.shortestSubarray(A, K);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//    return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
