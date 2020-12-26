
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double wt = 0;
        int cur = 0;
        for (auto& c : customers) {
            cur = max(cur, c[0]);
            cur += c[1];
            wt += cur - c[0];
        }
        return wt / (double)customers.size();
    }
};

//////////////////////////////////////////////////////////////////////////
double _solution_run(vector<vector<int>>& customers)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.averageWaitingTime(customers);
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
