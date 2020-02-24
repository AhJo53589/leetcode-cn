
//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
	int minimumLengthEncoding(vector<string>& words)
	{
		string ans;
		sort(words.rbegin(), words.rend(), [](const string& a, const string& b) { return a.size() < b.size(); });
		for (auto& word : words)
		{
			if (ans.find(word + "#") != string::npos) continue;
			ans += word + "#";
		}
		return ans.size();
	}
};

//////////////////////////////////////////////////////////////////////////
class Trie
{
public:
	Trie() : len(0) {}
	~Trie() 
	{ 
		for (int i = 0; i < 26; i++)
		{
			if (next[i] == nullptr) continue;
			delete next[i];
		}
	}

	int len;
	map<char, Trie*> next;
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) 
	{
		root = new Trie();
		int ans = 0;
		for (auto& word : words)
		{
			Trie* p = root;
			int len = 1;	// len for '#'
			for (size_t i = word.size() - 1; i < word.size(); i--)
			{
				if (p->next[word[i]] == nullptr)
				{
					p->next[word[i]] = new Trie();
				}
				p = p->next[word[i]];
				len++;
				if (p->len != 0)
				{
					ans -= p->len;
					p->len = 0;
				}
			}
			if (!p->next.empty()) continue;
			p->len = len;
			ans += len;
		}
		delete root;
		return ans;
    }

private:
	Trie* root;
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<string>& words)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.minimumLengthEncoding(words);
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
