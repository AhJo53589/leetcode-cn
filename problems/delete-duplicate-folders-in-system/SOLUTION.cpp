
//////////////////////////////////////////////////////////////////////////
class Trie {
public:
    Trie() {}

    void insert(string word) {
        Trie* node = this;
        for (auto c : word) {
            if (node->next[c - 'a'] == nullptr) {
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
        }
        node->is_string = true;
    }

    bool search(string word) {
        Trie* node = this;
        for (auto c : word) {
            if (node->next[c - 'a'] == nullptr) return false;
            node = node->next[c - 'a'];
        }
        return node->is_string;
    }

    bool startsWith(string prefix) {
        Trie* node = this;
        for (auto c : prefix) {
            if (node->next[c - 'a'] == nullptr) return false;
            node = node->next[c - 'a'];
        }
        return true;
    }

    vector<string> getString() {
        Trie* node = this;
        return getString(node, "");
    }

    vector<string> getString(Trie* node, string word) {
        vector<string> ans;
        bool flag = true;
        for (int i = 0; i < 26; i++) {
            if (node->next[i] == nullptr) continue;
            char c = 'a' + i;
            vector<string> r = getString(node->next[i], word + c);
            for (auto &s : r) {
                ans.emplace_back(s);
            }
            flag = false;
        }
        if (flag) {
            ans.push_back(word);
        }
        return ans;
    }

private:
    bool is_string = false;
    Trie* next[26] = { nullptr };
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Trie trie;

        for (auto path : paths) {
            string p;
            for (auto s : path) {
                p += s;
            }
            trie.insert(p);
        }

        vector<string> ans = trie.getString();
        printVectorT(ans);
        return {};
    }
};

//////////////////////////////////////////////////////////////////////////
vector<vector<string>> _solution_run(vector<vector<string>>& paths)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.deleteDuplicateFolder(paths);
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
