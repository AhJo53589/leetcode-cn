
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<vector<int>> dw(27, vector<int>(27, 0));
        string res;
        for (auto p : votes) {
            for (int i = 0; i < p.length(); i++) {
                //i是名次 p[i]是选择的队伍
                dw[p[i] - 'A'][i] ++;
                dw[p[i] - 'A'].back() = 26 - (p[i] - 'A');
            }
        }
        sort(dw.begin(), dw.end(), greater<vector<int>>());

        for (int i = 0; i < dw.size(); i++) {
            if (dw[i].back() != 0)
                res.push_back(26 - (dw[i].back() - 'A'));
        }
        return res;

    }
};


//////////////////////////////////////////////////////////////////////////
string _solution_run(vector<string>& votes)
{
    //int caseNo = 5;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

	printVectorT(votes);
	Solution sln;
	return sln.rankTeams(votes);
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
