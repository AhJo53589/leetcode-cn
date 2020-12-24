
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> ans(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {
            ans[i] = (ratings[i] > ratings[i - 1]) ? max(ans[i], ans[i - 1] + 1) : ans[i];
        }
        for (int i = ratings.size() - 2; i >= 0; i--) {
            ans[i] = (ratings[i] > ratings[i + 1]) ? max(ans[i], ans[i + 1] + 1) : ans[i];
        }
        return accumulate(ans.begin(), ans.end(), 0);
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& ratings)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.candy(ratings);
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
