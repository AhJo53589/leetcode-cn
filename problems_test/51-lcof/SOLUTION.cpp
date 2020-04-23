
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    long long merge_sort(vector<int>& q, int l, int r, vector<int>& tmp) {
        if (l >= r) return 0;

        int mid = l + (r - l) / 2;
        long long ans = merge_sort(q, l, mid, tmp) + merge_sort(q, mid + 1, r, tmp);

        int k = 0;
        int i = l;
        int j = mid + 1;
        while (i <= mid && j <= r) {
            if (q[i] <= q[j]) {
                tmp[k++] = q[i++];
            } else {  
                ans += mid - i + 1;
                tmp[k++] = q[j++];
            }
        }

        while (i <= mid) {
            tmp[k++] = q[i++];
        }
        while (j <= r) {
            tmp[k++] = q[j++];
        }
        for (int i = l, j = 0; i <= r;) {
            q[i++] = tmp[j++];
        }
        return ans;
    }

    int reversePairs(vector<int>& nums) {
        vector<int> tmp(nums.size(), 0);
        return merge_sort(nums, 0, nums.size() - 1, tmp);
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.reversePairs(nums);
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
