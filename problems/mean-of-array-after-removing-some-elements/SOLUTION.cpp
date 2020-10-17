
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    double trimMean(vector<int>& arr) {
        int d = arr.size() / 20;
        sort(arr.begin(), arr.end());
        long long sum = 0;
        for (int i = d; i < arr.size() - d; i++) {
            sum += arr[i];
        }
        double ans = (double)sum / (double)(arr.size() - d - d);
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
double _solution_run(vector<int>& arr)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.trimMean(arr);
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
