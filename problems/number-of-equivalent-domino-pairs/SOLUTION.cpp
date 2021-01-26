
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans = 0;
        vector<vector<int>> dic(10, vector<int>(10, 0));
        for (auto& d : dominoes) {
            int a = (d[0] <= d[1]) ? d[0] : d[1];
            int b = (d[0] <= d[1]) ? d[1] : d[0];
            dic[a][b]++;
            ans += dic[a][b] - 1;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& dominoes)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.numEquivDominoPairs(dominoes);
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
