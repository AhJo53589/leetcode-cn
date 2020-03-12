
//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
    void dfs(int n, int row, vector<int> col, vector<int> ld, vector<int> rd, vector<int>& pick, vector<vector<string>>& ans)
    {
        if (row == n)
        {
            vector<string> str(n, string(n, '.'));
            for (int i = 0; i < n; i++)
            {
                str[i][pick[i]] = 'Q';
            }
            ans.push_back(str);
            return;
        }

        // int pos = ~(col | ld | rd) & ((1 << n) - 1);
        vector<int> pos(n, 0);
        for (int i = 0; i < pos.size(); i++)
        {
            pos[i] = !(col[i] == 1 || ld[i] == 1 || rd[i] == 1);
        }

        // while (pos != 0)
        while (any_of(pos.begin(), pos.end(), [](const int& a) { return a == 1; }))
        {
            // pick[row] = (pos & -pos);
            for (int i = pos.size() - 1; i >= 0; i--)
            {
                if (pos[i] != 1) continue;
                pick[row] = i;
                break;
            }

            // (col | pick[row])
            vector<int> colTemp(col);
            colTemp[pick[row]] = 1;

            // ((ld | pick[row]) << 1)
            vector<int> ldTemp(ld);
            ldTemp[pick[row]] = 1;
            for (int i = 0; i < ldTemp.size() - 1; i++)
            {
                ldTemp[i] = ldTemp[i + 1];
            }
            ldTemp.back() = 0;

            // ((rd | pick[row]) >> 1)
            vector<int> rdTemp(rd);
            rdTemp[pick[row]] = 1;
            for (int i = rdTemp.size() - 1; i > 0; i--)
            {
                rdTemp[i] = rdTemp[i - 1];
            }
            rdTemp.front() = 0;

            dfs(n, row + 1, colTemp, ldTemp, rdTemp, pick, ans);

            // pos &= (pos - 1);
            for (int i = pos.size() - 1; i >= 0; i--)
            {
                if (pos[i] != 1) continue;
                pos[i] = 0;
                break;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<int> pick(n, 0);
        dfs(n, 0, vector<int>(n, 0), vector<int>(n, 0), vector<int>(n, 0), pick, ans);
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void dfs(int n, int row, int col, int ld, int rd, vector<int>& pick, vector<vector<string>>& ans)
    {
        if (row == n)
        {
            vector<string> str(n, string(n, '.'));
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (pick[i] & (1 << j))
                    {
                        str[i][j] = 'Q';
                        break;
                    }
                }
            }
            ans.push_back(str);
            return;
        }

        int pos = ~(col | ld | rd) & ((1 << n) - 1);
        while (pos != 0)
        {
            pick[row] = (pos & -pos);
            dfs(n, row + 1, (col | pick[row]), ((ld | pick[row]) << 1), ((rd | pick[row]) >> 1), pick, ans);
            pos &= (pos - 1);
        }
    }

    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        vector<int> pick(n, 0);
        dfs(n, 0, 0, 0, 0, pick, ans);
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<vector<string>> _solution_run(int n)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.solveNQueens(n);
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

#define USE_CHECKANSWER_CUSTOM
void _checkAnswer_custom(vector<vector<string>>& ans, TestCases& tc)
{
    _checkAnswer_custom_sort(ans, tc);
}