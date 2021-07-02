
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cnt;
        for (auto c : s) {
            cnt[c]++;
        }

        multimap<int, char> mm;
        for (auto [c, n] : cnt) {
            mm.insert({n, c});
        }

        string ans;
        for (auto [n, c] : mm) {
            for (int i = 0; i < n; i++) {
                ans += c;
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string s)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.frequencySort(s);
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
