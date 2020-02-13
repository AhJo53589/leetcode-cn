
//////////////////////////////////////////////////////////////////////////
bool exist(vector<vector<char>> &board, size_t i, size_t j, string word, unordered_set<size_t> visited)
{
	if (word.empty()) return true;
	if (board.size() == 0 || board.size() <= i) return false;
	if (board[0].size() == 0 || board[0].size() <= j) return false;
	if (visited.count(i * board[0].size() + j)) return false;

	if (board[i][j] != word.front()) return false;
	word = word.substr(1, word.size() - 1);
	visited.insert(i * board[0].size() + j);

	if (exist(board, i - 1, j, word, visited)) return true;
	if (exist(board, i + 1, j, word, visited)) return true;
	if (exist(board, i, j - 1, word, visited)) return true;
	if (exist(board, i, j + 1, word, visited)) return true;

	return false;
}

bool exist(vector<vector<char>>& board, string word)
{
	unordered_map<char, int> map_board;
	unordered_map<char, int> map_word;
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			map_board[board[i][j]]++;
		}
	}
	for (auto &c : word)
	{
		map_word[c]++;
		if (map_word[c] > map_board[c]) return false;
	}

	unordered_set<size_t> visited;
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] == word.front())
			{
				if (exist(board, i, j, word, visited)) return true;
			}
		}
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<vector<char>>& board, string word)
{
	return exist(board,word);
}

//#define USE_SOLUTION_CUSTOM
//bool _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

