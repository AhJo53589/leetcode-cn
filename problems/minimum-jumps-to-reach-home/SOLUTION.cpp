
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        if (x == 0) return 0;
        unordered_set<int> vi(forbidden.begin(), forbidden.end());
        vi.insert(0);

        queue<pair<int, bool>> que;
        que.push({ 0, false });

        int cnt = 0;
        while (!que.empty()) {
            cnt++;
            for (int len = que.size(); len > 0; len--) {
                auto [pos, jump] = que.front();
                que.pop();

                if (pos > 100000) continue;
                //if (pos > x + a * b) continue;

                if (pos + a == x) return cnt;
                if (vi.find(pos + a) == vi.end()) {
                    vi.insert(pos + a);
                    que.push({ pos + a, false });
                }

                if (jump) continue;
                if (pos - b == x) return cnt;
                if (pos - b >= 0 && vi.find(pos - b) == vi.end()) {
                    que.push({ pos - b, true });
                }
            }
        }

        return -1;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& forbidden, int a, int b, int x)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};
    printVectorT(forbidden);
    cout << a << ", " << b << ", " << x << endl;
    Solution sln;
    return sln.minimumJumps(forbidden, a, b, x);
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
