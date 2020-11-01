
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        vector<vector<int>> dd = { {0, 1}, {1, 0} };
        queue<pair<vector<int>, string>> que;
        que.push({ vector<int>{0, 0}, "" });
        while (!que.empty()) {
            auto [v, s] = que.front();
            que.pop();

            for (auto d : dd) {
                int dx = v[0] + d[0];
                int dy = v[1] + d[1];
                if (dx < 0 || dx > destination[0]) continue;
                if (dy < 0 || dy > destination[1]) continue;
                string ns = (d[0] == 0) ? s + "H" : s + "V";

                vector<int> nv = { dx, dy };
                k -= (nv == destination);
                if (k == 0) return ns;

                que.push({ nv, ns });
            }
        }
        return "";
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(vector<int>& destination, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(destination);
    cout << k << endl;
    Solution sln;
    return sln.kthSmallestPath(destination, k);
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
