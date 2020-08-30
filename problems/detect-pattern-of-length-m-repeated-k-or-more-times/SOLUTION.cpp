
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
		for (int i = 0; i < arr.size(); i++) {
			bool f = true;
			for (int t = 0; t < m && f; t++) {
				for (int j = 0; j < k && f; j++) {
					int nxt = i + j * m + t;
					if (nxt >= arr.size() || arr[i + t] != arr[nxt]) {
						f = false;
					}
				}
			}
			if (f) return true;
		}
		return false;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& arr, int m, int k)
{
    int caseNo = -1;
    static int caseCnt = 0;
    if (caseNo != -1 && caseCnt++ != caseNo) return {};
	printVectorT(arr);
	cout << m << ", " << k << endl;
	Solution sln;
	return sln.containsPattern(arr, m, k);
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
