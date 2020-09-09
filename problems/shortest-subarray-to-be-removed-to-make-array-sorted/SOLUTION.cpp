
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int f = arr.size() - 1;
        int b = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] >= arr[i - 1]) continue;
            f = i - 1;
            break;
        }
        for (int i = arr.size() - 2; i >= 0; i--) {
            if (arr[i] <= arr[i + 1]) continue;
            b = i + 1;
            break;
        }
        if (f == arr.size() - 1) return 0;
        
        int ans = arr.size() - 1;
        for (int i = f; i >= 0; i--) {
            if (b - i - 1 >= ans) break;
            for (int j = b; j < arr.size(); j++) {
                if (j - i - 1 >= ans) break;
                if (arr[i] <= arr[j]) {
                    ans = min(ans, j - i - 1);
                }
            }
        }
        //if (f + 1 == b) {   
            ans = min(ans, (int)arr.size() - f - 1);
            ans = min(ans, b);
        //}
        
        return ans;
        
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& arr)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.findLengthOfShortestSubarray(arr);
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
