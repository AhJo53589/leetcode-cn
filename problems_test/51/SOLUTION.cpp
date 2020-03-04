
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
	void solve(vector<string> &grid, int n, vector<vector<string>>& ans)
	{
		int i = grid.size() - n;
		for (int j = 0; j < grid[i].size(); j++)
		{
			if (grid[i][j] != '-') continue;
			vector<string> temp = grid;
			temp[i][j] = 'Q';
			for (auto d : dd)
			{
				int dx = i;
				int dy = j;
				while (true)
				{
                    dx += d[0];
                    dy += d[1];
                    if (dx < 0 || dx >= grid.size()) break;
                    if (dy < 0 || dy >= grid[0].size()) break;
                    temp[dx][dy] = '.';
				}
			}
			if (n - 1 == 0)
			{
				ans.push_back(move(temp));
				break;
			}
			solve(temp, n - 1, ans);
		}
	}

    vector<vector<string>> solveNQueens(int n) 
	{
		vector<vector<string>> ans;
		vector<string> grid(n, string(n, '-'));
		solve(grid, n, ans);
		return ans;
    }
private:
	vector<vector<int>> dd = { {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1},{-1,-1} };
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
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
