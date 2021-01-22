
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        reverse(A.begin(), A.end());
        int c = 0;

        for (int i = 0; (K != 0 || c != 0); i++) {
            if (i >= A.size()) {
                A.push_back(0);
            }

            int a = A[i];
            int b = K % 10;
            K /= 10;

            int sum = a + b + c;
            A[i] = (sum % 10);
            c = sum / 10;
        }

        reverse(A.begin(), A.end());
        return A;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& A, int K)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.addToArrayForm(A, K);
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
