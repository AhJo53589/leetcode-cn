
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) 
    {
        double x0 = (x1 + x2) / 2.0;
        double y0 = (y1 + y2) / 2.0;

        vector<double> p = { abs(x_center - x0) , abs(y_center - y0) };
        vector<double> q = { x2 - x0, y2 - y0 };

        double a1 = max(p[0] - q[0], 0.0);
        double a2 = max(p[1] - q[1], 0.0);
        return sqrt(a1 * a1 + a2 * a2) <= radius;   
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.checkOverlap(radius, x_center, y_center, x1, y1, x2, y2);
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
