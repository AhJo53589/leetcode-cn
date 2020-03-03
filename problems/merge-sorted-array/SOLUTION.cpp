
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int i = nums1.size() - 1;
        m--;
        n--;
        while (n >= 0)
        {
            while (m >= 0 && nums1[m] > nums2[n])
            {
                swap(nums1[i--], nums1[m--]);
            }
            swap(nums1[i--], nums2[n--]);
        }
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    sln.merge(nums1, m, nums2, n);
    return nums1;
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases& tc)
//{
//    return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
