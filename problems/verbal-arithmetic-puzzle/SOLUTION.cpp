


//////////////////////////////////////////////////////////////////////////
bool check(vector<vector<int>>& eq, int lv, vector<int>& en, int& inc)
{
	auto& cur_eq = eq[lv];
	int sum = inc;
	for (int i = 0; i < cur_eq.size(); i++)
	{
		sum += cur_eq[i] * en[i];
	}
	inc = sum / 10;
	return (sum % 10 == 0);
}

void dfs(vector<vector<int>>& eq, vector<vector<char>>& chars, int lv, int idx, int inc, vector<char>& ne, vector<int>& en, vector<bool>& zeroFlag, bool& ans)
{
	if (ans) return;
	if (idx == chars[lv].size())
	{
		//for (size_t i = 0; i < 26; i++)
		//{
		//	if (en[i] == -1) continue;
		//	char c = i + 'A';
		//	cout << c << ": " << en[i] << "\t";
		//}
		if (!check(eq, lv, en, inc))
		{
			//cout << "check failed" << endl;
			return;
		}
		//cout << "check success!" << endl;

		if (lv == 7)
		{
			ans = true;
			return;
		}
		dfs(eq, chars, lv + 1, 0, inc, ne, en, zeroFlag, ans);
	}

	auto& cur_eq = eq[lv];
	auto& cur_ch = chars[lv];

	if (idx < 0 || idx >= cur_ch.size()) return;
	char c = cur_ch[idx];
	for (int n = 0; n < 10; n++)
	{
		if (ne[n] != 'a') continue;
		if (n == 0 && zeroFlag[c - 'A']) continue;

		en[c - 'A'] = n;
		ne[n] = c;

		dfs(eq, chars, lv, idx + 1, inc, ne, en, zeroFlag, ans);

		en[c - 'A'] = -1;
		ne[n] = 'a';
	}
}

bool isSolvable(vector<string>& words, string result)
{
	vector<char> ne(10, 'a');
	vector<int> en(26, -1);
	vector<bool> zeroFlag(26, false);
	vector<vector<int>> equation(8, vector<int>(26, 0));
	vector<vector<char>> chars(8, vector<char>());

	words.push_back(result);
	for (size_t j = 0; j < words.size(); j++)
	{
		auto w = words[j];
		zeroFlag[w[0] - 'A'] = true;
		size_t d = 0;
		for (size_t i = w.size() - 1; i < w.size(); i--)
		{
			equation[d++][w[i] - 'A'] += (j == words.size() - 1) ? -1 : 1;
		}
	}
	unordered_set<char> us;
	for (size_t d = 0; d < 8; d++)
	{
		for (int i = 0; i < equation[d].size(); i++)
		{
			if (equation[d][i] == 0) continue;
			char c = i + 'A';
			if (us.count(c) != 0) continue;
			chars[d].push_back(c);
			us.insert(c);
		}
	}

	bool ans = false;
	dfs(equation, chars, 0, 0, 0, ne, en, zeroFlag, ans);
	return ans;
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<string>& words, string result)
{
	return isSolvable(words,result);
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
	return "../../problems/verbal-arithmetic-puzzle/tests.txt";
}

