
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) 
    {
        vector<vector<int>> re(n, vector<int>());
        for (auto& r : relation)
        {
            re[r[0]].push_back(r[1]);
        }

        int ans = 0;
        queue<int> que;
        que.push(0);
        while (k-- > 0)
        {
            int len = que.size();
            for (int i = 0; i < len; i++)
            {
                auto q = que.front();
                que.pop();

                for (auto r : re[q])
                {
                    ans += (k == 0 && r == n - 1);
                    que.push(r);
                }
            }
        }

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, vector<vector<int>>& relation, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.numWays(n, relation, k);
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
