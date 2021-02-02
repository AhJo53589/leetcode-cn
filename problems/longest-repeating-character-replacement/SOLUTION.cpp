
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26, 0);
        int maxn = 0;
        int i = 0;
        int j = 0;
        for (; j < s.size(); j++) {
            cnt[s[j] - 'A']++;
            maxn = max(maxn, cnt[s[j] - 'A']);
            if (j - i + 1 > maxn + k) {
                cnt[s[i] - 'A']--;
                i++;
            }
        }
        return j - i;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s, int k)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.characterReplacement(s, k);
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
