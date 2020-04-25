
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        vector<int> limit = { 2, 9, 5, 9 };
        vector<int> cnt(10, 0);
        for (auto n : A) {
            cnt[n]++;
        }

        vector<int> ans;
        if (!dfs(cnt, limit, ans)) return "";
        return to_string(ans[0]) + to_string(ans[1]) + ":" + to_string(ans[2]) + to_string(ans[3]);
    }

    bool dfs(vector<int>& cnt, vector<int>& limit, vector<int>& ans) {
        if (ans.size() == 4) return true;
        for (int i = limit[ans.size()]; i >= 0; i--) {
            i = (ans.size() == 1 && ans[0] == 2 && i == 9) ? 3 : i;

            if (cnt[i] == 0) continue;
            cnt[i]--;
            ans.push_back(i);
            if (dfs(cnt, limit, ans)) return true;
            ans.pop_back();
            cnt[i]++;
        }
        return false;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(vector<int>& A)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.largestTimeFromDigits(A);
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
