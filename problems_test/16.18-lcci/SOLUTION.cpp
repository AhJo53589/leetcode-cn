
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool patternMatching(string pattern, string value) {
        if (pattern.empty()) return value.empty();

        this->pattern = pattern;
        this->value = value;
        init();

        for (auto lc : letter_cnt) {
            string a = getWord(0, lc);
            string b = getWord(1, lc);
            if (valid(a, b)) return true;
        }
        return false;
    }

    string getWord(int target, vector<int>& lc) {
        char p = 'a' + target;
        for (int i = 0; i < pattern.size(); i++) {
            if (pattern[i] != p) continue;
            return value.substr(i * lc[1 - target], lc[target]);
            break;
        }
        return {};
    }

    bool valid(string& a, string& b) {
        if (!isSingle && a == b) return false;
        int j = 0;
        for (int i = 0; i < pattern.size(); i++) {
            string& t = (pattern[i] == 'a') ? a : b;
            if (j + t.size() > value.size()) return false;
            if (memcmp(&value[j], &t[0], t.size()) != 0) return false;
            j += t.size();
        }
        return (j == value.size());
    }

    void init() {
        int acnt = 0;
        int bcnt = 0;
        for (int i = 0; i < pattern.size(); i++) {
            acnt += (pattern[i] == 'a');
            bcnt += (pattern[i] == 'b');
        }
        isSingle = (acnt == 0 || bcnt == 0);

        if (acnt == 0) {
            letter_cnt.push_back({ 0, (int)value.size() / bcnt });
        }
        else if (bcnt == 0) {
            letter_cnt.push_back({ (int)value.size() / acnt, 0 });
        }
        else {
            for (int i = 0; i * acnt < value.size() + 1; i++) {
                if (((int)value.size() - i * acnt) % bcnt != 0) continue;
                letter_cnt.push_back({ i, ((int)value.size() - i * acnt) / bcnt });
            }
        }
    }

private:
    string pattern;
    string value;
    vector<vector<int>> letter_cnt;
    bool isSingle;
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string pattern, string value)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.patternMatching(pattern, value);
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
