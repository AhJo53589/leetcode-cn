
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        const int mod = 1e9 + 7;
        vector<int> distanceToLastNode(n, INT_MAX);
        distanceToLastNode.back() = 0;
        
        vector<vector<int>> path(n, vector<int>(n, 0));
        for (auto& edge : edges) {
            edge[0]--;
            edge[1]--;
            path[edge[0]][edge[1]] = edge[2];
            path[edge[1]][edge[0]] = edge[2];
        }
        
        vector<bool> vi(n, false);
        queue<int> que;
        que.push(n - 1);
        vi[n - 1] = true;
        while (!que.empty()) {
            auto q = que.front();
            que.pop();
            vi[q] = false;
            
            for (int i = 0; i < n; i++) {
                if (i == q) continue;
                if (path[q][i] == 0) continue;
                int dis = distanceToLastNode[q] + path[q][i];
                if (dis < distanceToLastNode[i]) {
                    distanceToLastNode[i] = dis;
                    if (!vi[i]) {
                        que.push(i);
                        vi[i] = true;
                    }
                }
            }            
        }
        
        vector<long long> cnt(n, 0);
        cnt.back() = 1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({distanceToLastNode.back(), n - 1});
        vi[n - 1] = true;
        while (!pq.empty()) {
            auto [dis, q] = pq.top();
            pq.pop();
            
            for (int i = 0; i < n; i++) {
                if (i == q) continue;
                if (path[q][i] == 0) continue;
                if (distanceToLastNode[i] <= dis) continue;
                cnt[i] += cnt[q];
                cnt[i] %= mod;
                if (!vi[i]) {
                    pq.push({distanceToLastNode[i], i});
                    vi[i] = true;
                }
            }
        }
        
        return cnt.front();
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, vector<vector<int>>& edges)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.countRestrictedPaths(n, edges);
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
