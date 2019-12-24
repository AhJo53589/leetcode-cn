
//////////////////////////////////////////////////////////////////////////
class Trie
{
public:
	Trie() {}

	void insert(const string& word) //插入单词
	{
		Trie* root = this;
		for (const auto& w : word) 
		{
			if (root->next[w - 'a'] == nullptr)
			{
				root->next[w - 'a'] = new Trie();
			}
			root = root->next[w - 'a'];
		}
		root->is_string = true;
	}

	bool search(const string& word) //查找单词
	{
		Trie* root = this;
		for (const auto& w : word)
		{
			if (root->next[w - 'a'] == nullptr) return false;
			root = root->next[w - 'a'];
		}
		return root->is_string;
	}

	bool startsWith(string prefix) //查找前缀
	{
		Trie* root = this;
		for (const auto& p : prefix) 
		{
			if (root->next[p - 'a'] == nullptr) return false;
			root = root->next[p - 'a'];
		}
		return true;
	}

private:
	bool is_string = false;
	Trie* next[26] = { nullptr };
};

//////////////////////////////////////////////////////////////////////////
//class Trie 
//{
//public:
//    /** Initialize your data structure here. */
//    Trie()
//	{
//
//    }
//
//    /** Inserts a word into the trie. */
//    void insert(string word)
//	{
//
//    }
//
//    /** Returns if the word is in the trie. */
//    bool search(string word) 
//	{
//
//    }
//
//    /** Returns if there is any word in the trie that starts with the given prefix. */
//    bool startsWith(string prefix)
//	{
//
//    }
//};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

//////////////////////////////////////////////////////////////////////////
//bool _solution_run(string word)
//{
//	return search(word);
//}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases& tc)
{
	vector<string> sf = tc.get<vector<string>>();
	vector<vector<string>> param = tc.get<vector<vector<string>>>();

	string ans = "[";
	Trie* obj = nullptr;
	for (size_t i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "Trie")
		{
			obj = new Trie();
			ans += "null";
		}
		else if (sf[i] == "insert")
		{
			obj->insert(param[i][0]);
			ans += "null";
		}
		else if (sf[i] == "search")
		{
			bool r = obj->search(param[i][0]);
			ans += r ? "true" : "false";
		}
		else if (sf[i] == "startsWith")
		{
			bool r = obj->startsWith(param[i][0]);
			ans += r ? "true" : "false";
		}
		ans += ",";
	}
	ans.pop_back();
	ans += "]";
	return ans;
}

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

