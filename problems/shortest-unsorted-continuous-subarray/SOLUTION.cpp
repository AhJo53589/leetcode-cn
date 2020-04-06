
//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        stack<int> st;
        int l = nums.size() - 1;
        int r = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            while (!st.empty() && nums[st.top()] > nums[i])
            {
                l = min(l, st.top());
                st.pop();
            }
            st.push(i);
        }
        st = stack<int>();
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] < nums[i])
            {
                r = max(r, st.top());
                st.pop();
            }
            st.push(i);
        }
        return (r > l) ? r - l + 1 : 0;
    }
};

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int l = 0;
        int r = 0;
        int minNum = nums[nums.size() - 1];
        for (int i = nums.size() - 1; i >= 0; i--) 
        {
            l = (nums[i] > minNum) ? i : l;
            minNum = min(minNum, nums[i]);
        }
        int maxNum = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            r = (nums[i] < maxNum) ? i : r;
            maxNum = max(maxNum, nums[i]);
        }
        return (r > l) ? r - l + 1 : 0;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.findUnsortedSubarray(nums);
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
