
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int l = 0;
        int r = A.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (A[m - 1] < A[m] && A[m] > A[m + 1]) return m;
            if (A[m - 1] < A[m]) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        return l;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& A)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.peakIndexInMountainArray(A);
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
