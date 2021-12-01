
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> name = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        
        vector<pair<int, int>> ranking;
        for (int i = 0; i < score.size(); i++) {
            ranking.push_back({score[i], i});
        }
        sort(ranking.rbegin(), ranking.rend());

        vector<string> ans(score.size());
        for (int rk = 0; rk < ranking.size(); rk++) {
            ans[ranking[rk].second] = (rk < 3) ? name[rk] : to_string(rk + 1);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<string> _solution_run(vector<int>& score)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.findRelativeRanks(score);
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
