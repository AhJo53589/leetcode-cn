
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> dic;
        for (auto n : arr1) {
            dic[n] = 1001 + n;
        }
        for (int i = 0; i < arr2.size(); i++) {
            dic[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(), [&dic](const int& a, const int& b) {
            return dic[a] < dic[b];
        });
        return arr1;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& arr1, vector<int>& arr2)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.relativeSortArray(arr1, arr2);
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
