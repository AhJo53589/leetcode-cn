
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int ans = 0;
        int maxIndex = 0;
        for (int i = 1; i < A.size(); i++) {
            ans = max(ans, A[i] + A[maxIndex] - i + maxIndex);
            maxIndex = (A[maxIndex] + maxIndex <= A[i] + i) ? i : maxIndex;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& A)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.maxScoreSightseeingPair(A);
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
