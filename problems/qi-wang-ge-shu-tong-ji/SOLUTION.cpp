
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int expectNumber(vector<int>& scores) {
        if (scores.empty()) return 0;
        set<int> s;
        for (auto x : scores) {
            s.insert(x);
        }
        return s.size();
    }
};


//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& scores)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.expectNumber(scores);
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
