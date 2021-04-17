
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        sort(points.begin(), points.end());

        vector<int> ans(queries.size(), 0);
        int result = 0;
        for (int i = 0; i < queries.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                if (j != 0 && points[j] == points[j - 1]) {
                    ans[i] += result;
                    continue;
                }
                int x = points[j][0] - queries[i][0];
                int y = points[j][1] - queries[i][1];
                int z = queries[i][2];
                result = (x * x + y * y <= z * z) ? 1 : 0;
                ans[i] += result;
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<vector<int>>& points, vector<vector<int>>& queries)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.countPoints(points, queries);
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
