
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m)
    {
        map<int, int> mp;
        for (int i = 0; i < m; i++)
        {
            mp[i + 1] = i;
        }

        vector<int> ans(queries.size(), 0);
        for (int i = 0; i < queries.size(); i++)
        {
            int n = queries[i];
            ans[i] = mp[n];

            for (auto& p : mp)
            {
                if (p.second >= mp[n]) continue;
                p.second++;
            }
            mp[n] = 0;
        }

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& queries, int m)
{
    int caseNo = -1;
    static int caseCnt = 0;
    if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(queries);

    Solution sln;
    return sln.processQueries(queries, m);
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
