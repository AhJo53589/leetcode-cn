
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> perm(n);
        for (int i = 0; i < perm.size(); i++) {
            perm[i] = i;
        }
        vector<int> def = perm;

        int ans = 0;
        vector<int> arr(perm.size());
        while (ans == 0 || perm != def) {
            for (int i = 0; i < perm.size(); i++) {
                if (i % 2 == 0) {
                    arr[i] = perm[i / 2];
                }
                else {
                    arr[i] = perm[n / 2 + (i - 1) / 2];
                }
            }
            perm = arr;
            ans++;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.reinitializePermutation(n);
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
