
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (gcd(i, j) != 1) continue;
                ans.push_back(to_string(j) + "/" + to_string(i));
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<string> _solution_run(int n)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << n << endl;
    Solution sln;
    return sln.simplifiedFractions(n);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
