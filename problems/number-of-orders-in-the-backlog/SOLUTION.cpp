
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        const int mod = 1e9 + 7;
        long long ans = 0;
        vector<priority_queue<pair<int, int>>> pq(2);

        for (auto& v : orders) {
            v[0] = (v[2] == 0) ? v[0] : -v[0];
            pq[v[2]].push({ v[0], v[1] });
            ans += v[1];

            while (!pq[0].empty() && !pq[1].empty() && pq[0].top().first >= -pq[1].top().first) {
                vector<pair<int, int>> q(2);
                for (int i = 0; i < pq.size(); i++) {
                    q[i] = pq[i].top();
                    pq[i].pop();
                }

                int t = min(q[0].second, q[1].second);
                q[0].second -= t;
                q[1].second -= t;
                ans -= 2 * t;

                for (int i = 0; i < pq.size(); i++) {
                    if (q[i].second == 0) continue;
                    pq[i].push(q[i]);
                }
            }
        }

        return ans % mod;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& orders)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorVectorT(orders);
    Solution sln;
    return sln.getNumberOfBacklogOrders(orders);
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
