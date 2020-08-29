
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int> cnt(4, 0);
        unordered_map<char, int> u;
        u['U'] = 0;
        u['D'] = 1;
        u['L'] = 2;
        u['R'] = 3;
        for (auto c : moves) {
            cnt[u[c]]++;
        }
        return cnt[0] == cnt[1] && cnt[2] == cnt[3];
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string moves)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.judgeCircle(moves);
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
