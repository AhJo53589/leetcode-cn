
//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
	struct TrieNode {
		bool flag;
		map<char, TrieNode*> next;
		TrieNode() : flag(false) {}
	};
	TrieNode* root;
	void init(const vector<string>& words) {
		root = new TrieNode;
		for (auto& w : words) {
			auto node = root;
			for (auto c : w) {
				if (!node->next.count(c)) {
					node->next[c] = new TrieNode;
				}
				node = node->next[c];
			}
			node->flag = true;
		}
	}

	void dfs(const string& s, const vector<vector<int> >& dp, int i, vector<string>& v, vector<string>& res) {
		if (i == 0) {
			string t;
			for (auto it = v.rbegin(); it != v.rend(); ++it) {
				t += *it + " ";
			}
			t.pop_back();
			res.push_back(t);
			return;
		}
		for (auto j : dp[i]) {
			v.push_back(s.substr(j, i - j));
			dfs(s, dp, j, v, res);
			v.pop_back();
		}
	}
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		// 构建字典树
		init(wordDict);
		unordered_set<char> cs;
		for (auto& w : wordDict) {
			for (auto c : w) {
				cs.insert(c);
			}
		}
		for (auto c : s) {
			if (cs.count(c) == 0) {
				return {};
			}
		}
		// 动态规划部分
		int N = s.size();
		vector<vector<int> > dp(N + 1);
		dp[0] = vector<int>{ -1 };
		for (int i = 0; i < N; ++i) {
			if (dp[i].empty()) continue;
			int j = i;
			auto node = root;
			while (j < N && node->next.count(s[j])) {
				node = node->next[s[j++]];
				if (node->flag) {
					dp[j].push_back(i);
				}
			}
		}
		// 路径回溯构建所有可能的结果字符串
		vector<string> v;
		vector<string> res;
		dfs(s, dp, N, v, res);
		return res;
	}
};


//////////////////////////////////////////////////////////////////////////
class Solution {
public:
	vector<string> wordBreak(string s, vector<string>& wordDict)
	{
		if (!wordBreak_139(s, wordDict)) return {};

		size_t validEnd = 0;
		vector<vector<string>> dp(s.size() + 1, vector<string>());

		for (size_t i = 0; i < s.size(); i++)
		{
			if (i == validEnd + 1) return {};
			if (i != 0 && dp[i].empty()) continue;
			for (auto& word : wordDict)
			{
				size_t newEnd = i + word.size();
				if (newEnd > s.size()) continue;
				if (memcmp(&s[i], &word[0], word.size()) != 0) continue;
				validEnd = max(validEnd, newEnd);
				if (i == 0)
				{
					dp[newEnd].push_back(word);
					continue;
				}
				for (auto& d : dp[i])
				{
					dp[newEnd].push_back(d + " " + word);
				}
			}
		}

		return dp.back();
	}

	bool wordBreak_139(string& s, vector<string>& wordDict)
	{
		size_t validEnd = 0;
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for (size_t i = 0; i < s.size(); i++)
		{
			if (i == validEnd + 1) return false;
			if (!dp[i]) continue;
			for (auto& word : wordDict)
			{
				size_t newEnd = i + word.size();
				if (newEnd > s.size()) continue;
				if (memcmp(&s[i], &word[0], word.size()) != 0) continue;

				validEnd = max(validEnd, newEnd);
				dp[newEnd] = true;
			}
		}
		return dp.back();
	}
};

//////////////////////////////////////////////////////////////////////////
vector<string> _solution_run(string s, vector<string>& wordDict)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.wordBreak(s, wordDict);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//	return {};
//}

#define USE_CHECKANSWER_CUSTOM
void _checkAnswer_custom(vector<string>& ans, TestCases& tc)
{
	vector<string> answer = tc.get<vector<string>>();
	sort(ans.begin(), ans.end());
	sort(answer.begin(), answer.end());
	cout << checkAnswer<decltype(ans)>(ans, answer) << endl;
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
