
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        vector<int> ans(nums.size(), -1);
        stack<int> st;
        for (int i = 0; i < nums.size() * 2; i++)
        {
            int j = i % nums.size();

            while (!st.empty() && nums[st.top()] < nums[j])
            {
                ans[st.top()] = j;
                st.pop();
            }
            st.push(j);
        }

        for (auto& n : ans)
        {
            n = (n == -1) ? -1 : nums[n];
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
    printVectorT(nums);
    Solution sln;
    return sln.nextGreaterElements(nums);
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
