
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        vector<int> inDegree(n, 0);
        vector<int> outDegree(n, 0);
        vector<vector<int>> lst(n, vector<int>());
        vector<int> depth(n, -1);
        for (auto v : dependencies) {
            inDegree[v[1] - 1]++;
            outDegree[v[0] - 1]++;
            lst[v[0] - 1].push_back(v[1] - 1);
        }

        queue<int> que;
        for (auto i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] == 0) que.push(i);
        }

        int ans = 0;
        int cnt = 0;
        priority_queue<vector<int>, vector<vector<int>>, less<vector<int>>> pq;
        while (true) {
            while (!que.empty()) {
                auto q = que.front();
                que.pop();
                pq.push({ outDegree[q], q });
            }

            if (pq.empty()) break;
            while (!pq.empty()) {
                auto t = pq.top();
                pq.pop();
                for (auto l : lst[t[1]]) {
                    if (--inDegree[l] == 0) que.push(l);
                }

                cnt++;
                if (cnt == k) break;
            }
            cnt = 0;
            ans++;
        }

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, vector<vector<int>>& dependencies, int k)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.minNumberOfSemesters(n, dependencies, k);
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
