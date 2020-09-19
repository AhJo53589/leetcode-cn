
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0;
        for (int k = 1; k <= arr.size(); k += 2) {
            for (int i = 0; i < arr.size(); i++) {
                if (i + k > arr.size()) break;
                for (int j = 0; j < k; j++) {
                    ans += arr[i + j];
                }
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& arr)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};
    printVectorT(arr);
    Solution sln;
    return sln.sumOddLengthSubarrays(arr);
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
