
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;
        vector<int> chCount(26, 0);
        bool sameAll = true;
        bool sameTwo = false;
        vector<int> dif(2, -1);
        bool difTwo = false;

        for (int i = 0; i < s.size(); i++) {
            int n1 = s[i] - 'a';
            int n2 = goal[i] - 'a';
            chCount[n1]++;
            sameTwo = (chCount[n1] > 1) ? true : sameTwo;

            if (n1 != n2) {
                sameAll = false;
                if (difTwo) return false;
                if (dif[0] == -1) {
                    dif[0] = n1;
                    dif[1] = n2;
                }
                else {
                    if (dif[0] != n2 || dif[1] != n1) return false;
                    difTwo = true;
                }
            }
        }
        return sameAll ? sameTwo : difTwo;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string s, string goal)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.buddyStrings(s, goal);
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
