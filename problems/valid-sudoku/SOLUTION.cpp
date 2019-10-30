
vector<int> convertInt(vector<char>& line)
{
	vector<int> nums;
	for (char c : line)
	{
		if (c == '.') continue;

		int n = c - 48;
		nums.push_back(n);
	}
	return nums;
}

bool checkDuplicate(vector<char>& line)
{
	vector<int> nums = convertInt(line);
	sort(nums.begin(), nums.end());

	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i - 1] == nums[i]) return true;
	}

	return false;
}


//////////////////////////////////////////////////////////////////////////
bool isValidSudoku(vector<vector<char>>& board)
{
	for (int i = 0; i < 9; i++)
	{
		if (checkDuplicate(board[i])) return false;
	}

	vector<char> grid[9];
	for (int i = 0; i < 9; i++)
	{
		vector<char> line;
		for (int j = 0; j < 9; j++)
		{
			line.push_back(board[j][i]);

			// 把81宫格合并成9宫格
			int k = i / 3 + j / 3 * 3;
			grid[k].push_back(board[i][j]);
		}
		if (checkDuplicate(line)) return false;
	}

	for (int i = 0; i < 9; i++)
	{
		if (checkDuplicate(grid[i])) return false;
	}

	return true;
}


//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<vector<char>>& board)
{
	return isValidSudoku(board);
}

//#define USE_SOLUTION_CUSTOM
//bool _solution_custom(TestCases &tc)
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
	return "../../problems/valid-sudoku/tests.txt";
}

