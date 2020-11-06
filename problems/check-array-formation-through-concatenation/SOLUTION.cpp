
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, vector<int>> dic;
        for (auto p : pieces) {
            dic[p[0]] = p;
        }

        for (int i = 0; i < arr.size();) {
            if (dic.find(arr[i]) == dic.end()) return false;
            auto f = dic[arr[i]];
            for (int j = 0; j < f.size(); j++, i++) {
                if (arr[i] != f[j]) return false;
            }
        }
        return true;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& arr, vector<vector<int>>& pieces)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.canFormArray(arr, pieces);
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
