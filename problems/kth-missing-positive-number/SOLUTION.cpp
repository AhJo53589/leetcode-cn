
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = 0;
        for (auto a : arr) {
            while (++n != a) {
                if (--k == 0) return n;
            }
        }
        while (k-- != 0) {
            ++n;
        }
        return n;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& arr, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(arr);
    cout << k << endl;
    Solution sln;
    return sln.findKthPositive(arr, k);
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
