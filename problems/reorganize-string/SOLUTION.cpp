
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string reorganizeString(string S) {
        vector<int> cnt(26);
        for (auto c : S) {
            cnt[c - 'a']++;
        }
        vector<pair<int, char>> vp;
        for (int i = 0; i < cnt.size(); i++) {
            if (cnt[i] == 0) continue;
            vp.push_back({cnt[i], 'a' + i});
        }
        sort(vp.rbegin(), vp.rend());

        if (vp.front().first > S.size() / 2 + (S.size() % 2)) return "";

        int pos = 0;
        for (auto [n, c] : vp) {
            for (int i = 0; i < n; i++) {
                S[getIndex(S.size(), pos++)] = c;
            }
        }

        return S;
    }

    int getIndex(int len, int i) {
        return (i * 2 >= len) ? i * 2 - len + (len % 2 == 0) : i * 2;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string S)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.reorganizeString(S);
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
