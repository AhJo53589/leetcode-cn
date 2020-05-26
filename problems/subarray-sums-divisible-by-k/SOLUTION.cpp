
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        for (int i = 0, n = A.size(), sum = 0; i < n; i++) {
            sum = ((sum + A[i]) % K + K) % K;
            ++cnt[sum];
        }
        int anw = 0;
        for (auto p : cnt) {
            anw += p.second * (p.second - 1) / 2;
        }
        return anw;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& A, int K)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.subarraysDivByK(A, K);
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
