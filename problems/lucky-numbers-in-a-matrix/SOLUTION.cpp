
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            int mnj = 0;
            for (int j = 1; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] > matrix[i][mnj]) continue;
                mnj = j;
            }
            int mxi = 0;
            for (int i = 1; i < matrix.size(); i++)
            {
                if (matrix[i][mnj] < matrix[mxi][mnj]) continue;
                mxi = i;
            }
            if (mxi == i) return { matrix[mxi][mnj] };
        }
        return {};
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<vector<int>>& matrix)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.luckyNumbers(matrix);
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
