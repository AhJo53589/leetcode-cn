
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        sort(tasks.rbegin(), tasks.rend());
        this->tasks = tasks;
        this->sessionTime = sessionTime;
        vi = vector<bool>(tasks.size(), false);

        dfs(0, 0, 0, 0);
        return ans;
    }

    void dfs(int idx, int finish, int lastTime, int cnt) {
        if (cnt >= ans) return;
        if (finish == tasks.size()) {
            ans = min(ans, cnt);
            return;
        }

        bool flag = false;
        for (int i = idx + 1; i < tasks.size(); i++) {
            if (vi[i]) continue;
            if (i != 0 && !vi[i - 1] && tasks[i] == tasks[i - 1]) continue;

            if (lastTime >= tasks[i]) {
                flag = true;

                vi[i] = true;
                dfs(i, finish + 1, lastTime - tasks[i], cnt);
                vi[i] = false;
            }
        }

        if (flag) return;
        for (int i = 0; i < tasks.size(); i++) {
            if (vi[i]) continue;
            if (i != 0 && !vi[i - 1] && tasks[i] == tasks[i - 1]) continue;

            vi[i] = true;
            dfs(i, finish + 1, sessionTime - tasks[i], cnt + 1);
            vi[i] = false;
        }
    }

private:
    vector<int> tasks;
    int sessionTime;
    vector<bool> vi;

    int ans = INT_MAX;
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& tasks, int sessionTime)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.minSessions(tasks, sessionTime);
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
