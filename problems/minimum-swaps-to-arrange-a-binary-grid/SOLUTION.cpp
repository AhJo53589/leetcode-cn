
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> zeroCnt(grid.size(), grid.size());
        for (int i = 0; i < grid.size(); i++) {
            for (int j = grid[i].size() - 1; j >= 0; j--) {
                if (grid[i][j] == 0) continue;
                zeroCnt[i] = grid[i].size() - j - 1;
                break;
            }
        }

        int ans = 0;
        for (int row = 0; row < grid.size() - 1; row++) {
            int t = findRow(zeroCnt, row);
            if (t == -1) return -1;
            ans += t - row;
        }
        return ans;
    }

    int findRow(vector<int>& zeroCnt, int row) {
        int cnt = zeroCnt.size() - row - 1;
        if (zeroCnt[row] >= cnt) return row;

        int prev = zeroCnt[row];
        for (int i = row + 1; i < zeroCnt.size(); i++) {
            swap(zeroCnt[i], prev);
            if (prev >= cnt) return i;
        }
        return -1;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& grid)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.minSwaps(grid);
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
