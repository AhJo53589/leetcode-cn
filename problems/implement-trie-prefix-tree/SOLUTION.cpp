
//////////////////////////////////////////////////////////////////////////
class Trie
{
public:
	Trie() {}
	~Trie() 
	{
		for (int i = 0; i < 26; i++)
		{
			if (next[i] == nullptr) continue;
			delete(next[i]);
			next[i] = nullptr;
		}
	}

	void insert(const string& word)
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

	bool search(const string& word)
	{
		Trie* root = this;
		for (const auto& w : word)
		{
			if (root->next[w - 'a'] == nullptr) return false;
			root = root->next[w - 'a'];
		}
		return root->is_string;
	}

	bool startsWith(string prefix)
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
//int _solution_run(int)
//{
//}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{
	vector<string> sf = tc.get<vector<string>>();
	vector<string> sp = tc.get<vector<string>>();
	vector<string> ans;

	Trie *obj = nullptr;
	for (auto i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "Trie")
		{
			obj = new Trie();
			ans.push_back("null");
		}
		else if (sf[i] == "insert")
		{
			TestCases stc(sp[i]);
			string word = stc.get<string>();
			obj->insert(word);
			ans.push_back("null");
		}
		else if (sf[i] == "search")
		{
			TestCases stc(sp[i]);
			string word = stc.get<string>();
			bool r = obj->search(word);
			ans.push_back(convert<string>(r));
		}
		else if (sf[i] == "startsWith")
		{
			TestCases stc(sp[i]);
			string prefix = stc.get<string>();
			bool r = obj->startsWith(prefix);
			ans.push_back(convert<string>(r));
		}
	}
	delete obj;

	return convert<string>(ans);
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
