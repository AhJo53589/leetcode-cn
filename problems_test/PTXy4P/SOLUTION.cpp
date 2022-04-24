
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int getMinimumTime(vector<int>& time, vector<vector<int>>& fruits, int limit) {
        int ans = 0;
        for (auto& f : fruits) {
            int a = f[1] / limit + (f[1] % limit != 0);
            ans += a * time[f[0]];
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& time, vector<vector<int>>& fruits, int limit)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.getMinimumTime(time, fruits, limit);
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
