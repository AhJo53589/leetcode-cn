
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, int> vi;
        vi[src] = 0;

        unordered_map<int, vector<pair<int, int>>> fdic;
        for (auto& f : flights) {
            fdic[f[0]].emplace_back(f[1], f[2]);
        }

        queue<pair<int, int>> que;
        que.push({src, 0});
        while (k-- >= 0) {
            for (int len = (int)que.size(); len > 0; len--) {
                auto [pos, price] = que.front();
                que.pop();

                for (auto [d, p] : fdic[pos]) {
                    if (vi.find(d) != vi.end() && vi[d] <= price + p) continue;
                    vi[d] = price + p;
                    que.push({d, price + p});
                }
            }
        }

        return vi.find(dst) == vi.end() ? -1 : vi[dst];
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, vector<vector<int>>& flights, int src, int dst, int k)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.findCheapestPrice(n, flights, src, dst, k);
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
