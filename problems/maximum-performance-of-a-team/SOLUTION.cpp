
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) 
    {
        const int mod = 1000000007;

        vector<vector<int>> es;
        for (int i = 0; i < efficiency.size(); i++)
        {
            es.push_back({ efficiency[i], speed[i] });
        }
        sort(es.rbegin(), es.rend());

        long long ans = 0;
        long long sum = 0;
        long long eff = INT_MAX;
        priority_queue<int, vector<int>, greater<int>> que;
        for (int i = 0; i < es.size(); i++)
        {
            eff = es[i][0];
            sum += es[i][1];
            que.push(es[i][1]);
            if (--k < 0)
            {
                sum -= que.top();
                que.pop();
            }
            ans = max(ans, sum * eff);
        }
        return ans % mod;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, vector<int>& speed, vector<int>& efficiency, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << n << ", " << k << endl;
    printVectorT(speed);
    printVectorT(efficiency);
    Solution sln;
    return sln.maxPerformance(n, speed, efficiency, k);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//    return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
