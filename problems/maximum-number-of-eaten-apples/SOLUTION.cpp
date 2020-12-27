
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int ans = 0;
        int i = 0;
        while (!pq.empty() || i < apples.size()) {
            while (!pq.empty() && pq.top().first <= i) {
                pq.pop();
            }
            if (i < apples.size() && apples[i] != 0) {
                pq.push({ i + days[i], apples[i] });
            }
            if (!pq.empty()) {
                ans++;
                auto t = pq.top();
                pq.pop();
                t.second--;
                if (t.second != 0) {
                    pq.push(t);
                }
            }
            i++;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& apples, vector<int>& days)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};
    printVectorT(apples);
    printVectorT(days);
    Solution sln;
    return sln.eatenApples(apples, days);
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
