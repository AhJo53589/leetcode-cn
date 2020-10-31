
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int longestMountain(vector<int>& A) {
		int ans = 0;
		int st = 0;
		int cnt = 1;
		for (int i = 1; i < A.size(); i++) {
			if (A[i] == A[i - 1]) {
				st = 0;
				cnt = 1;
				continue;
			}

			switch (st) {
			case 0:
				if (A[i] > A[i - 1]) {
					st = 1;
					cnt++;
				}
				break;
			case 1:
				if (A[i] < A[i - 1]) {
					st = 2;
				}
                cnt++;
				break;
			case 2:
				if (A[i] < A[i - 1]) {
					cnt++;
				}
				else {
					st = 1;
					cnt = 2;
				}
				break;
			}

			ans = (st == 2) ? max(ans, cnt) : ans;
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
	return sln.longestMountain(A);
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
