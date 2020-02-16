
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) 
	{
		int ans = 0;
        for (auto i = 0; i < grid.size(); i++)
        {
			for (auto j = 0; j < grid[i].size(); j++)
			{
				if (grid[i][j] >= 0) continue;
				ans += (grid[i].size() - j);
				break;
			}
        }
		return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& grid)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.countNegatives(grid);
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
