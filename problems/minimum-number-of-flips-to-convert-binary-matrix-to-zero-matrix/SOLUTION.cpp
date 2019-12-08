
vector<vector<int>> turn(vector<vector<int>> m, size_t x, size_t y)
{
    m[x][y] = m[x][y] == 0 ? 1 : 0;
    if (x + 1 < m.size())
    {
        m[x + 1][y] = m[x + 1][y] == 0 ? 1 : 0;
    }
    if (x - 1 < m.size())
    {
        m[x - 1][y] = m[x - 1][y] == 0 ? 1 : 0;
    }
    if (y + 1 < m[0].size())
    {
        m[x][y + 1] = m[x][y + 1] == 0 ? 1 : 0;
    }
    if (y - 1 < m[0].size())
    {
        m[x][y - 1] = m[x][y - 1] == 0 ? 1 : 0;
    }
    return m;
}

bool check(vector<vector<int>>& m)
{
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[0].size(); j++)
        {
            if (m[i][j] == 1) return false;
        }
    }
    return true;
}

//////////////////////////////////////////////////////////////////////////
int minFlips(vector<vector<int>>& mat)
{
    if (check(mat)) return 0;
    set<vector<vector<int>>> s;
    queue<vector<vector<int>>> que;
    s.insert(mat);
    que.push(mat);

    int ans = 0;
    while (ans < 100)
    {
        ans++;
        queue<vector<vector<int>>> que2;
        while(!que.empty())
        {
            vector<vector<int>> m = que.front();
            que.pop();
            for (int i = 0; i < m.size(); i++)
            {
                for (int j = 0; j < m[0].size(); j++)
                {
                    vector<vector<int>> m2 = turn(m, i, j);
                    if (s.count(m2) != 0) continue;
                    s.insert(m2);
                    if (check(m2)) return ans;
                    que2.push(m2);
                }
            }
        }   
        swap(que, que2);
    }
    ans = (ans == 100) ? -1 : ans;
    return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& mat)
{
	return minFlips(mat);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/tests.txt";
}

