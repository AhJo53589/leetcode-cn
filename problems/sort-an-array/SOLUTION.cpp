
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int parttion(vector<int>& nums, int l, int r)
    {
        int m = l;
        for (int i = l; i < r; i++)
        {
            if (nums[i] < nums[r])
            {
                swap(nums[m++], nums[i]);
            }
        }
        swap(nums[m], nums[r]);
        return m;
    }

    void quicksort(vector<int>& nums, int l, int r)
    {
        if (l >= r) return;
        int m = parttion(nums, l, r);
        quicksort(nums, l, m - 1);
        quicksort(nums, m + 1, r);
    }

    vector<int> sortArray(vector<int>& nums) 
    {
        quicksort(nums, 0, nums.size() - 1);
        return nums;
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
    return sln.sortArray(nums);
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
