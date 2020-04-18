
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findMinFibonacciNumbers(int k) 
    {
        vector<int> f(2, 1);
        while (f.back() < k)
        {
            f.push_back(f[f.size() - 2] + f[f.size() - 1]);
        }
        if (f.back() == k) return 1;
        int ans = 0;
        for (int i = f.size() - 1; i >= 0; i--)
        {
            if (k < f[i]) continue;
            k -= f[i];
            ans++;
            if (k == 0) break;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.findMinFibonacciNumbers(k);
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
