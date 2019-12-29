


//////////////////////////////////////////////////////////////////////////
bool check(vector<string>& words, string& result, vector<int>& en)
{
	int left = 0;
	int right = 0;
	for (auto w : words)
	{
		//cout << w << ": ";
		int t = 0;
		for (auto c : w)
		{
			t *= 10;
			t += en[c - 'A'];
			//cout << en[c - 'A'];
		}
		left += t;
		//cout << "\t";
	}
	//cout << endl << result << ": ";
	for (auto c : result)
	{
		right *= 10;
		right += en[c - 'A'];
		//cout << en[c - 'A'];
	}
	//cout << endl;
	return left == right;
}

bool preCheck(vector<char>& chars, int cntBack, vector<int>& en)
{
	int t = 0;
	for (int i = 0; i < cntBack; i++)
	{
		t += en[chars[i] - 'A'];
	}
	t -= en[chars[cntBack - 1] - 'A'] * 2;
	return (t % 10 == 0);
}

void dfs(vector<string>& words, string& result, vector<char>& chars, int idx, int cntBack, vector<char>& ne, vector<int>& en, vector<bool>& zeroFlag, bool& ans)
{
	if (ans == true) return;
	if (idx == chars.size())
	{
		if (check(words, result, en))
		{
			ans = true;
		}
		return;
	}

	if (idx == cntBack && !preCheck(chars, cntBack, en)) return;

	for (int i = 0; i < 10; i++)
	{
		if (ne[i] != 'a') continue;
		if (i == 0 && zeroFlag[chars[idx] - 'A']) continue;

		ne[i] = chars[idx];
		en[chars[idx] - 'A'] = i;

		dfs(words, result, chars, idx + 1, cntBack, ne, en, zeroFlag, ans);

		ne[i] = 'a';
		en[chars[idx] - 'A'] = -1;
	}
}

bool isSolvable(vector<string>& words, string result) 
{
	vector<char> ne(10, 'a');
	vector<int> en(26, -1);
	vector<bool> zeroFlag(26, false);
	set<char> wordsBack;

	set<char> cs;
	for (auto w : words)
	{
		zeroFlag[w[0] - 'A'] = true;
		wordsBack.insert(w.back());
		for (auto c : w) cs.insert(c);
	}
	zeroFlag[result[0] - 'A'] = true;
	wordsBack.insert(result.back());
	for (auto c : result) cs.insert(c);

	vector<char> chars(wordsBack.begin(), wordsBack.end());
	int cntBack = chars.size();
	for (auto c : cs)
	{
		if (wordsBack.count(c) != 0) continue;
		chars.push_back(c);
	}

	bool ans = false;
	dfs(words, result, chars, 0, cntBack, ne, en, zeroFlag, ans);
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

