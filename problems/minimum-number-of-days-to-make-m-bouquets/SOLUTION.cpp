
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        day = bloomDay;
        this->k = k;

        fin = vector<int>(day.size(), 0);
        priority_queue<int, vector<int>, less<int>> pq;
        priority_queue<int, vector<int>, less<int>> pq_out;
        for (int i = 0; i < day.size(); i++) {
            if (i >= k) {
                pq_out.push(day[i - k]);
                while (!pq_out.empty() && pq_out.top() == pq.top()) {
                    pq_out.pop();
                    pq.pop();
                }
            }
            pq.push(day[i]);
            if (i >= k - 1) {
                fin[i - k + 1] = pq.top();
            }
        }

        int ans = INT_MAX;
        dfs(0, m, 0, ans);
        return ans == INT_MAX ? -1 : ans;
    }

    void dfs(int start, int m, int val, int& ans) {
        if (day.size() - start < m * k) return;
        if (val >= ans) return;
        if (m == 0 && start <= day.size()) {
            ans = min(ans, val);
            return;
        }

        for (int i = start; i < day.size(); i++) {
            dfs(i + k, m - 1, max(val, fin[i]), ans);
        }
    }

private:
    vector<int> day;
    vector<int> fin;
    int k;
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& bloomDay, int m, int k)
{
    int caseNo = -1;
    static int caseCnt = 0;
    if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(bloomDay);
    cout << m << ", " << k << endl;
    Solution sln;
    return sln.minDays(bloomDay, m, k);
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
