
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int>> rect(101, vector<int>());
        for (int i = 0; i < rectangles.size(); i++) {
            rect[rectangles[i][1]].push_back(rectangles[i][0]);
        }
        for (auto& rt : rect) {
            sort(rt.begin(), rt.end());
        }

        vector<int> ans(points.size(), 0);
        for (int i = 0; i < points.size(); i++) {
            int cnt = 0;
            int l = points[i][0];
            for (int h = points[i][1]; h < rect.size(); h++) {
                auto& rt = rect[h];
                auto t = lower_bound(rt.begin(), rt.end(), l) - rt.begin();
                cnt += (int)rt.size() - t;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<vector<int>>& rectangles, vector<vector<int>>& points)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.countRectangles(rectangles, points);
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
