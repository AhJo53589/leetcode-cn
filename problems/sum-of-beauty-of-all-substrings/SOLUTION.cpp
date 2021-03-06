
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            vector<int> cnt(26, 0);
            multiset<int> ms;
            for (int j = i; j < s.size(); j++) {
                int c = s[j] - 'a';
                if (cnt[c] != 0) {
                    ms.erase(ms.find(cnt[c]));
                }
                cnt[c]++;
                ms.insert(cnt[c]);
                if (ms.size() < 2) continue;
                ans += *ms.rbegin() - *ms.begin();
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.beautySum(s);
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
