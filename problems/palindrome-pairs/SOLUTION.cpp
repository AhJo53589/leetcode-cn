
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (checkSide(words[i], words[j])) {
                    ans.push_back({ i, j });
                }
                if (checkSide(words[j], words[i])) {
                    ans.push_back({ j, i });
                }
            }
        }
        return ans;
    }

    bool checkSide(string& s1, string& s2) {
        int len = min(s1.size(), s2.size());
        for (int i = 0; i < len; i++) {
            if (s1[i] != s2[s2.size() - i - 1]) return false;
        }

        if (s1.size() < s2.size()) {
            return checkPalindrome(s2, 0, s2.size() - len - 1);
        }
        if (s1.size() > s2.size()) {
            return checkPalindrome(s1, len, s1.size() - 1);
        }
        return true;
    }

    bool checkPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<string>& words)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.palindromePairs(words);
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
