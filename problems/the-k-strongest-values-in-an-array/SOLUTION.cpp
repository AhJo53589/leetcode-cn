
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int m = arr[(arr.size() - 1) / 2];

        sort(arr.begin(), arr.end(), [m](const int& a, const int& b) {
            if (abs(a - m) == abs(b - m)) return a > b;
            return (abs(a - m) > abs(b - m));
        });

        vector<int> ans(k, 0);
        for (int i = 0; i < ans.size(); i++) {
            ans[i] = arr[i];
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& arr, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.getStrongest(arr, k);
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
