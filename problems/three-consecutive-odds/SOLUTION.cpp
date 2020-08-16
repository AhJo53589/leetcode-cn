
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for (int i = 2; i < arr.size(); i++) {
            if (arr[i] % 2 == 1 && arr[i - 1] % 2 == 1 && arr[i - 2] % 2 == 1) return true;
        }
        return false;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& arr)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.threeConsecutiveOdds(arr);
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
