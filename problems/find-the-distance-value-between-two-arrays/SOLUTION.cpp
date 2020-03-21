
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) 
    {
        int ans = 0;
        for (auto& a : arr1)
        {
            int flag = 1;
            for (auto& b : arr2)
            {
                if (abs(a - b) <= d)
                {
                    flag = 0;
                    break;
                }
            }
            ans += flag;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& arr1, vector<int>& arr2, int d)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.findTheDistanceValue(arr1, arr2, d);
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
