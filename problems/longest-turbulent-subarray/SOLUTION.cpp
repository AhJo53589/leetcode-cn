
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        arr.push_back(arr.back());

        int ans = 1;
        int start = 0;
        int dir = 0; 
        
        for (int i = 1; i < arr.size(); i++) {
            int d = (arr[i] == arr[i - 1]) ? 0 : (arr[i] - arr[i - 1]) / abs(arr[i] - arr[i - 1]);
            
            ans = (d != 0) ? max(ans, 2) : ans;
            ans = (abs(dir - d) == 2) ? max(ans, i - start + 1) : ans;
            start = (dir == 0 || abs(dir - d) != 2) ? i - 1 : start;
            dir = d;
        }
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
	return sln.maxTurbulenceSize(arr);
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
