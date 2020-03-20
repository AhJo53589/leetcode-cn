
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void buildHeap(vector<int>& nums)
    {
        for (int i = nums.size() / 2 - 1; i >= 0; i--)
        {
            adjustHeap(nums, i);
        }
    }

    void adjustHeap(vector<int>& nums, int idx)
    {
        for (int i = idx; i * 2 + 1 < nums.size();)
        {
            int t = i * 2 + 1;
            t += (t + 1 < nums.size() && nums[t + 1] > nums[t]);
            if (nums[i] > nums[t]) break;
            swap(nums[i], nums[t]);
            i = t;
        }
    }

    vector<int> getLeastNumbers(vector<int>& arr, int k)
    {
        if (k == 0) return {};
        vector<int> ans(arr.begin(), arr.begin() + k);
        buildHeap(ans);
        for (int i = k; i < arr.size(); i++)
        {
            if (arr[i] >= ans[0]) continue;
            ans[0] = arr[i];
            adjustHeap(ans, 0);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& arr, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.getLeastNumbers(arr, k);
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

#define USE_CHECKANSWER_CUSTOM
void _checkAnswer_custom(vector<int>& ans, TestCases& tc)
{
    _checkAnswer_custom_sort(ans, tc);
}