
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int getDp(vector<vector<int>>& hats, int res, int index, vector<vector<int>>& cache) {
        if (res == 0) {
            return 1;
        }
        if (index == 41) {
            return 0;
        }
        if (cache[res][index] != -1) {
            return cache[res][index];
        }
        int ret = getDp(hats, res, index + 1, cache);
        for (int i = 0; i < hats.size(); i++) {
            if (!(res & (1 << i))) {
                continue;
            }
            bool find = false;
            for (int j = 0; j < hats[i].size(); j++) {
                if (hats[i][j] == index) {
                    find = true;
                    break;
                }
            }
            if (find) {
                ret += getDp(hats, res - (1 << i), index + 1, cache);
                ret %= 1000000007;
            }
        }
        return cache[res][index] = ret;
    }

    int numberWays(vector<vector<int>>& hats) {
        vector<vector<int>> cache(1 << hats.size(), vector<int>(41, -1));
        return getDp(hats, (1 << hats.size()) - 1, 1, cache);
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& hats)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.numberWays(hats);
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
