
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int len = 10;
        unordered_map<char, int> dic = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        unordered_map<int, int> cnt;
        vector<string> ans;

        int t = 0;
        for (int i = 0; i < s.size(); i++) {
            t = ((t << 2) | dic[s[i]]) & ((1 << (len * 2)) - 1);
            if (i < len - 1) continue;
            if (++cnt[t] == 2) {
                ans.push_back(s.substr(i - len + 1, len));
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<string> _solution_run(string s)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.findRepeatedDnaSequences(s);
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
