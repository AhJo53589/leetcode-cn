
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
		sort(arr.begin(), arr.end());
		int ans = arr[1] - arr[0];
		for (int i = 2; i < arr.size(); i++) {
			if (ans != arr[i] - arr[i - 1]) return false;
		}
		return true;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& arr)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.canMakeArithmeticProgression(arr);
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
