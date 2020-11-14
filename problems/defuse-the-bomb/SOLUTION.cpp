
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans(code.size(), 0);
        if (k == 0) return ans;
        for (int i = 0; i < code.size(); i++) {
            if (k > 0) {
                for (int j = 1; j <= k; j++) {
                    ans[i] += code[(i + j) % code.size()];
                }
            }
            else {
                for (int j = 1; j <= -k; j++) {
                    ans[i] += code[(code.size() + i - j) % code.size()];
                }
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& code, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(code);
    cout << k << endl;
    Solution sln;
    return sln.decrypt(code, k);
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
