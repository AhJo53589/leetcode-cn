
//////////////////////////////////////////////////////////////////////////
class Trie {
public:
    Trie() {
        //next = vector<Trie*>(26, nullptr);
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
    }

    void add(string& s, int i) {
        if (i == s.size()) {
            isEnd = true;
            return;
        }

        int idx = s[i] - 'a';
        if (next[idx] == nullptr) {
            next[idx] = new Trie();
        }
        next[idx]->add(s, i + 1);
    }

    string findRoot(string& s, int i) {
        if (i == s.size()) return s;
        if (isEnd) return s.substr(0, i);
        int idx = s[i] - 'a';
        if (next[idx] == nullptr) return s;
        return next[idx]->findRoot(s, i + 1);
    }

    Trie* next[26];
    bool isEnd = false;
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        t = new Trie();
        for (auto s : dict) {
            t->add(s, 0);
        }

        string ans;
        stringstream ss(sentence);
        string temp;
        while (ss >> temp) {
            ans += t->findRoot(temp, 0);
            ans += " ";
        }
        if (ans.back() == ' ') {
            ans.pop_back();
        }
        return ans;
    }

private:
    Trie* t = nullptr;
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(vector<string>& dictionary, string sentence)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.replaceWords(dictionary, sentence);
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
