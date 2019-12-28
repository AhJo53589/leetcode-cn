


//////////////////////////////////////////////////////////////////////////
class Trie
{
public:
	Trie() {}
	void insert(string word)
	{
		Trie* node = this;
		for (auto c : word)
		{
			if (node->next[c - 'a'] == nullptr)
			{
				node->next[c - 'a'] = new Trie();
			}
			node = node->next[c - 'a'];
		}
		node->is_string = true;
	}

	bool search(string word)
	{
		Trie* node = this;
		for (auto c : word)
		{
			if (node->next[c - 'a'] == nullptr) return false;
			node = node->next[c - 'a'];
		}
		return node->is_string;
	}

	bool startsWith(string prefix)
	{
		Trie* node = this;
		for (auto c : prefix)
		{
			if (node->next[c - 'a'] == nullptr) return false;
			node = node->next[c - 'a'];
		}
		return true;
	}

private:
	bool is_string = false;
	Trie* next[26] = { nullptr };
};

void find(vector<vector<char>>& board, int x, int y, string fstr, set<vector<int>> &vi, set<string>& ret, Trie& trie, vector<vector<int>>& dd)
{
	if (vi.count({ x, y }) != 0) return;
	if (x < 0 || x >= board.size()) return;
	if (y < 0 || y >= board[0].size()) return;
	fstr += board[x][y];
	if (trie.search(fstr))
	{
		ret.insert(fstr);
	}
	if (!trie.startsWith(fstr)) return;

	vi.insert({ x, y });
	for (auto d : dd)
	{
		int dx = x + d[0];
		int dy = y + d[1];
		find(board, dx, dy, fstr, vi, ret, trie, dd);
	}
	vi.erase({ x, y });
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
{
	set<vector<int>> vi;
	set<string> ret;
	vector<vector<int>> dd = { {0, 1}, {0, -1}, {1,0},{-1,0} };

	Trie trie;
	for (auto w : words) trie.insert(w);

	for (int x = 0; x < board.size(); x++)
	{
		for (int y = 0; y < board[0].size(); y++)
		{
			find(board, x, y, "", vi, ret, trie, dd);
		}
	}

	vector<string> ans(ret.begin(), ret.end());
	return ans;
}

//////////////////////////////////////////////////////////////////////////
vector<string> _solution_run(vector<vector<char>>& board, vector<string>& words)
{
	return findWords(board,words);
}

//#define USE_SOLUTION_CUSTOM
//vector<string> _solution_custom(TestCases &tc)
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
	return "../../problems/_test_1/tests.txt";
}

