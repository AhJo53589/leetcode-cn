
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> dic;
        for (auto c : allowed) {
            dic.insert(c);
        }

        int ans = 0;
        for (auto& s : words) {
            bool flag = true;
            for (auto c : s) {
                if (dic.find(c) == dic.end()) {
                    flag = false;
                    break;
                }
            }
            ans += flag;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string allowed, vector<string>& words)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.countConsistentStrings(allowed, words);
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
