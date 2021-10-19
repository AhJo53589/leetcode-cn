
//////////////////////////////////////////////////////////////////////////
class Trie {
public:
    bool isEnd = false;
    vector<Trie*> next;

    Trie() {
        next = vector<Trie*>(26, nullptr);
    }

    void insert(const string& word) {
        Trie* node = this;
        for (auto c : word) {
            if (node->next[c - 'a'] == nullptr) {
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }
};

class WordDictionary {
public:
    WordDictionary() {}

    void addWord(string word) {
        t.insert(word);
    }

    bool search(string word) {
        return dfs(&t, word, 0);
    }

    bool dfs(Trie* node, const string& word, int idx) {
        if (idx == word.size()) return node->isEnd;

        char c = word[idx];
        if (c != '.') {
            if (node->next[c - 'a'] == nullptr) return false;
            return dfs(node->next[c - 'a'], word, idx + 1);
        }
        else {
            for (int i = 0; i < 26; i++) {
                c = 'a' + i;
                if (node->next[c - 'a'] == nullptr) continue;
                if (dfs(node->next[c - 'a'], word, idx + 1)) return true;
            }
        }
        return false;
    }

private:
    Trie t;
};


/**
* Your WordDictionary object will be instantiated and called as such:
* WordDictionary* obj = new WordDictionary();
* obj->addWord(word);
* bool param_2 = obj->search(word);
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

	WordDictionary *obj = nullptr;
	for (auto i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "WordDictionary")
		{
			obj = new WordDictionary();
			ans.push_back("null");
		}
		else if (sf[i] == "addWord")
		{
			TestCases stc(sp[i]);
			string word = stc.get<string>();
			obj->addWord(word);
			ans.push_back("null");
		}
		else if (sf[i] == "search")
		{
			TestCases stc(sp[i]);
			string word = stc.get<string>();
			bool r = obj->search(word);
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
