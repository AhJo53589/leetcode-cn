
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxUniqueSplit(string s) {
        dfs(s, 0);
        return ans;
    }

    void dfs(string& s, int pos) {
        if (s.size() - pos + us.size() <= ans) return;
        if (pos == s.size()) {
            ans = max(ans, (int)us.size());
            return;
        }

        string temp;
        for (int i = pos; i < s.size(); i++) {
            temp += s[i];
            if (us.find(temp) == us.end()) {
                us.insert(temp);
                dfs(s, i + 1);
                us.erase(temp);
            }
        }
    }
private:
    int ans = 0;
    unordered_set<string> us;
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << s << endl;
    Solution sln;
    return sln.maxUniqueSplit(s);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//    return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
