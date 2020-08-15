
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int i = 0;
        int t = 0;
        while (t < k && i < arr.size() - 1) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
            else {
                t = 0;
            }
            t++;
            i++;
        }
        return arr[i];
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& arr, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.getWinner(arr, k);
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
