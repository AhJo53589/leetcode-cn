
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int ans = 0;
        for (int i = 0; i < 201; i++) {
            for (int j = 0; j < 201; j++) {
                ans += check(circles, i, j);
            }
        }
        return ans;
    }

    bool check(vector<vector<int>>& circles, int x, int y) {
        for (auto& circle : circles) {
            int a = x - circle[0];
            int b = y - circle[1];
            int r = circle[2];
            if (a * a + b * b <= r * r) return true;
        }
        return false;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& circles)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.countLatticePoints(circles);
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
