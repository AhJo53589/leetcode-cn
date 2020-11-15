
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> cnt1(26, 0);
        vector<int> cnt2(26, 0);

        for (auto c : word1) {
            cnt1[c - 'a']++;
        }
        for (auto c : word2) {
            cnt2[c - 'a']++;
        }

        for (int i = 0; i < cnt1.size(); i++) {
            if (cnt1[i] != 0 && cnt2[i] == 0) return false;
            if (cnt1[i] == 0 && cnt2[i] != 0) return false;
        }

        sort(cnt1.rbegin(), cnt1.rend());
        sort(cnt2.rbegin(), cnt2.rend());
        return cnt1 == cnt2;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string word1, string word2)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.closeStrings(word1, word2);
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
