
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> dic;
        for (auto& s : startWords) {
            int x = trans(s);
            for (int i = 0; i < 26; i++) {
                if (x & (1 << i)) continue;
                dic.insert(x | (1 << i));
            }
        }

        int ans = 0;
        for (auto& s : targetWords) {
            int x = trans(s);
            ans += (dic.find(x) != dic.end());
        }
        return ans;
    }

    int trans(string& s) {
        int ans = 0;
        for (auto& c : s) {
            int x = c - 'a';
            ans |= (1 << x);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<string>& startWords, vector<string>& targetWords)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.wordCount(startWords, targetWords);
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
