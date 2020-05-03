
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        vector<string> start;
        unordered_set<string> end;
        for (auto& p : paths) {
            start.push_back(p[0]);
            end.insert(p[1]);
        }
        for (auto& s : start) {
            end.erase(s);
        }
        return *end.begin();
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(vector<vector<string>>& paths)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.destCity(paths);
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
