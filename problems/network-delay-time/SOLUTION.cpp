
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> paths(n, vector<int>(n, -1));
        vector<int> vi(n, INT_MAX);

        for (auto &t : times) {
            paths[t[0] - 1][t[1] - 1] = t[2];
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k - 1});
        vi[k - 1] = 0;

        while (!pq.empty()) {
            auto [t, n] = pq.top();
            pq.pop();

            for (int i = 0; i < paths[n].size(); i++) {
                if (paths[n][i] == -1) continue;
                int time = t + paths[n][i];
                if (time >= vi[i]) continue;
                pq.push({time, i});
                vi[i] = time;
            }
        }

        bool fin = true;
        int ans = 0;
        for (auto v : vi) {
            if (v == INT_MAX) {
                fin = false;
                break;
            }
            ans = max(ans, v);
        }
        return fin ? ans : -1;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& times, int n, int k)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.networkDelayTime(times, n, k);
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
