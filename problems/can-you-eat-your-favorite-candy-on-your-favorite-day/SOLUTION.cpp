
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        vector<long long> psum(candiesCount.size() + 1, 0);
        for (int i = 1; i < psum.size(); i++) {
            psum[i] = psum[i - 1] + candiesCount[i - 1];
        }

        vector<bool> ans(queries.size());
        for (int i = 0; i < ans.size(); i++) {
            int type = queries[i][0];
            long long day = queries[i][1];
            long long cap = queries[i][2];

            long long ax = psum[type + 1] - candiesCount[type] + 1;
            long long ay = psum[type + 1];
            //cout << ax << ", " << ay << endl;

            long long bx = day + 1LL;
            long long by = cap * (day + 1LL);
            //cout << bx << ", " << by << endl;

            ans[i] = (ax >= bx && ax <= by) || (ay >= bx && ay <= by)
                || (bx >= ax && bx <= ay) || (by >= ax && by <= ay);
        }

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<bool> _solution_run(vector<int>& candiesCount, vector<vector<int>>& queries)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.canEat(candiesCount, queries);
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
