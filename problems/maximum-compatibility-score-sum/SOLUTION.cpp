
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        sc = vector<vector<int>>(students.size(), vector<int>(mentors.size(), 0));
        for (int i = 0; i < students.size(); i++) {
            for (int j = 0; j < mentors.size(); j++) {
                int s = 0;
                for (int k = 0; k < students[i].size(); k++) {
                    s += (students[i][k] == mentors[j][k]);
                }
                sc[i][j] = s;
            }
        }

        vi = vector<bool>(students.size(), false);
        dfs(0, 0);
        return ans;
    }

    void dfs(int score, int i) {
        if (i == vi.size()) {
            ans = max(ans, score);
            return;
        }
        for (int j = 0; j < vi.size(); j++) {
            if (vi[j]) continue;
            vi[j] = true;
            dfs(score + sc[i][j], i + 1);
            vi[j] = false;
        }
    }

private:
    vector<vector<int>> sc;
    vector<bool> vi;
    int ans = 0;
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& students, vector<vector<int>>& mentors)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.maxCompatibilitySum(students, mentors);
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
