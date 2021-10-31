
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<unordered_set<char>> keyboard(3);
        keyboard[0] = unordered_set<char> {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
        keyboard[1] = unordered_set<char> {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        keyboard[2] = unordered_set<char> {'z', 'x', 'c', 'v', 'b', 'n', 'm'};

        vector<string> ans;
        for (auto& w : words) {
            int line = -1;
            for (auto c : w) {
                auto C = toupper(c);
                c = tolower(c);
                int cur = -1;
                for (int i = 0; i < keyboard.size(); i++) {
                    if (keyboard[i].find(c) != keyboard[i].end() ||
                    keyboard[i].find(C) != keyboard[i].end()) {
                        cur = i;
                        break;
                    }
                }
                if (line != -1 && line != cur) {
                    line = -2;
                    break;
                }
                line = cur;
            }
            if (line >= 0) {
                ans.push_back(w);
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<string> _solution_run(vector<string>& words)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.findWords(words);
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
