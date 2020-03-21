
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int f(long long x)
    {
        int cnt = 0;
        while (x != 1)
        {
            x = (x % 2) ? x * 3 + 1 : x / 2;
            ++cnt;
        }
        return cnt;
    }

    int getKth(int lo, int hi, int k) 
    {
        vector<int> a;
        for (int i = lo; i <= hi; ++i)
        {
            a.push_back(i);
        }
        sort(a.begin(), a.end(), [&](int x, int y)->bool { return f(x) == f(y) ? x < y : f(x) < f(y); });
        return a[k - 1];
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int lo, int hi, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.getKth(lo, hi, k);
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
