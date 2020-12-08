
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> ans;
        backtrack(ans, S, 0);
        return ans;
    }

    bool backtrack(vector<int>& ans, string& s, int pos) {
        if (pos == s.size()) return ans.size() >= 3;
        long long val = 0;
        long long sum = (ans.size() < 2) ? -1 : (long long)ans[ans.size() - 2] + ans.back();
        for (int i = pos; i < s.size(); i++) {
            if (i > pos && s[pos] == '0') break;
            val = val * 10 + s[i] - '0';
            if (val > INT_MAX) break;
            if (sum != -1 && sum < val) break;
            if (sum == -1 || sum == val) {
                ans.push_back(val);
                if (backtrack(ans, s, i + 1)) return true;
                ans.pop_back();
            }
        }
        return false;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(string S)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.splitIntoFibonacci(S);
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
