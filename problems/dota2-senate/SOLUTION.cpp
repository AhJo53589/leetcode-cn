
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string predictPartyVictory(string senate) {
        vector<queue<int>> que(2);
        for (int i = 0; i < senate.size(); ++i) {
            int idx = (senate[i] == 'R') ? 0 : 1;
            que[idx].push(i);
        }

        while (!que[0].empty() && !que[1].empty()) {
            int win = (que[0].front() < que[1].front()) ? 0 : 1;
            que[win].push(que[win].front() + senate.size());

            que[0].pop();
            que[1].pop();
        }
        return !que[0].empty() ? "Radiant" : "Dire";
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string senate)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.predictPartyVictory(senate);
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
