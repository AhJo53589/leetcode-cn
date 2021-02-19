
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        A.push_back(0);
        
        int ans = 0;
        vector<int> cnt(2, 0);
        for (int i = 0, j = 0; j < A.size(); i++) {
            while (cnt[0] <= K && j < A.size()) {
                cnt[A[j++]]++;
            }
            ans = max(ans, j - i - 1);
            cnt[A[i]]--;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& A, int K)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.longestOnes(A, K);
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
