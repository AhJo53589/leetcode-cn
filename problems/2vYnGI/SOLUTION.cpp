
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        const int mod = 1e9 + 7;
        int ans = 0;
        sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());
        int j = drinks.size() - 1;
        for (int i = 0; i < staple.size(); i++) {
            while (j >= 0 && staple[i] + drinks[j] > x) j--;
            if (j == -1) break;
            ans += j + 1;
            ans %= mod;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& staple, vector<int>& drinks, int x)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.breakfastNumber(staple, drinks, x);
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
