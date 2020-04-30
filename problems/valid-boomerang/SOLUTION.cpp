
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        //斜率公式变形： (x3-x2)(y2-y1) = (x2-x1)(y3-y2)
        return (points[2][0] - points[1][0]) * (points[1][1] - points[0][1]) != (points[1][0] - points[0][0]) * (points[2][1] - points[1][1]);
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<vector<int>>& points)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.isBoomerang(points);
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
