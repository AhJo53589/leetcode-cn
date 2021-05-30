
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq2;

        for (int i = 0; i < servers.size(); i++) {
            pq.push({ servers[i], i, 0 });
        }

        vector<int> ans(tasks.size());
        int i = 0;
        while (true) {
            while (!pq2.empty()) {
                auto [t, w, j] = pq2.top();
                if (t > i && !pq.empty()) break;
                pq.push({ w, j, t });
                pq2.pop();
            }

            auto [w, j, t] = pq.top();
            pq.pop();

            ans[i] = j;
            pq2.push({ max(t, i) + tasks[i], w, j });
            if (++i >= tasks.size()) break;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& servers, vector<int>& tasks)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};
    printVectorT(servers);
    printVectorT(tasks);
    Solution sln;
    return sln.assignTasks(servers, tasks);
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
