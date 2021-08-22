
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int _min = 0;
        int _max = 0;
        for (int i = 0; i < mat.size(); i++) {
            sort(mat[i].begin(), mat[i].end());
            _min += mat[i].front();
            _max += mat[i].back();
        }
        if (_min > target) return abs(_min - target);

        int limit = min(abs(_min - target), abs(_max - target));

        unordered_set<int> dp;
        for (int i = 0; i < mat.size(); i++) {
            unordered_set<int> dp2;
            for (int j = 0; j < mat[0].size(); j++) {
                if (i == 0) {
                    dp2.insert(mat[i][j]);
                }
                else {
                    for (auto it = dp.begin(); it != dp.end(); it++) {
                        if (mat[i][j] + *it <= limit + target) {
                            dp2.insert(mat[i][j] + *it);
                        }
                    }
                }
            }
            swap(dp, dp2);
        }

        int ans = INT_MAX;
        for (auto it = dp.begin(); it != dp.end(); it++) {
            ans = min(ans, abs(*it - target));
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& mat, int target)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    //printVectorVectorT(mat);
    cout << target << endl;
    Solution sln;
    return sln.minimizeTheDifference(mat, target);
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
