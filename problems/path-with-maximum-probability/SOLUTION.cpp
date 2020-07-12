
//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
    double maxProbability(int n, vector<vector<int>>& _edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> edges(n);
        int m = _edges.size();
        for (int i = 0; i < m; ++i) {
            const auto& edge = _edges[i];
            // cout << edge[0] << " " << edge[1] << "\n";
            edges[edge[0]].emplace_back(edge[1], succProb[i]);
            edges[edge[1]].emplace_back(edge[0], succProb[i]);
        }

        vector<double> dist(n);
        dist[start] = 1.0;

        vector<int> used(n);
        priority_queue<pair<double, int>> pq;
        pq.emplace(1.0, start);

        while (!pq.empty()) {
            auto [prob, u] = pq.top();
            // cout << "u = " << u << "\n";
            pq.pop();
            used[u] = true;
            for (auto [v, np] : edges[u]) {
                // cout << "v = " << v << "\n";
                if (!used[v] && prob * np > dist[v]) {
                    dist[v] = prob * np;
                    pq.emplace(dist[v], v);
                }
            }
        }

        return dist[end];
    }
};

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<bool> vi(n, false);

        vector<vector<pair<double, int>>> path(n, vector<pair<double, int>>());
        for (int i = 0; i < edges.size(); i++) {
            auto& e = edges[i];
            path[e[0]].push_back({ succProb[i], e[1] });
            path[e[1]].push_back({ succProb[i], e[0] });
        }

        priority_queue<pair<double, int>> pq;
        pq.push({ 1, start });

        while (!pq.empty()) {
            auto q = pq.top();
            pq.pop();

            if (vi[q.second]) continue;
            vi[q.second] = true;

            if (q.second == end) return q.first;

            for (auto& p : path[q.second]) {
                if (vi[p.second]) continue;
                pq.push({ q.first * p.first, p.second });
            }
        }

        return 0;
    }
};

//////////////////////////////////////////////////////////////////////////
double _solution_run(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end)
{
    int caseNo = -1;
    static int caseCnt = 0;
    if (caseNo != -1 && caseCnt++ != caseNo) return {};

	//cout << n << endl;
	//printVectorVectorT(edges);
	//printVectorT(succProb);
	//cout << start << ", " << end << endl;
	Solution sln;
	return sln.maxProbability(n, edges, succProb, start, end);
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
