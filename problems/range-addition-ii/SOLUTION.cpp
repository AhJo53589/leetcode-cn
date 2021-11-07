
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int row = m;
        int col = n;
        for (auto& op : ops) {
            row = min(row, op[0]);
            col = min(col, op[1]);
        }
        return row * col;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int m, int n, vector<vector<int>>& ops)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.maxCount(m, n, ops);
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
