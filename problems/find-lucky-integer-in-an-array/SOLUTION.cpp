
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findLucky(vector<int>& arr) 
    {
        map<int, int> cnt;
        for (auto& n : arr)
        {
            cnt[n]++;
        }
        for (auto it = cnt.rbegin(); it != cnt.rend(); it++)
        {
            if (it->first != it->second) continue;
            return it->first;
        }
        return -1;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& arr)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.findLucky(arr);
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
