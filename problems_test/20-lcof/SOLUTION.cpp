
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isNumber(string s) {
        vector<unordered_map<char, int>> states{
            {{ ' ', 0 }, { 's', 1 }, { 'd', 2 }, { '.', 4 }},   // 0 
            {{ 'd', 2 }, { '.', 4 }},                           // 1
            {{ 'd', 2 }, { '.', 3 }, { 'e', 5 }, { ' ', 8 } },  // 2
            {{ 'd', 3 }, { 'e', 5 }, { ' ', 8 }},               // 3
            {{ 'd', 3 }},                                       // 4
            {{ 's', 6 }, { 'd', 7 }},                           // 5
            {{ 'd', 7 }},                                       // 6
            {{ 'd', 7 }, { ' ', 8 }},                           // 7
            {{ ' ', 8 }}                                        // 8
        };

        int p = 0;
        char t;
        for (auto c : s) {
            if (c >= '0' && c <= '9') {
                t = 'd';
            }
            else if (c == '+' || c == '-') {
                t = 's';
            }
            else {
                t = c;
            }

            if (states[p].count(t) == 0) return false;
            p = (int)states[p][t];
        }
        return p == 2 || p == 3 || p == 7 || p == 8;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string s)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.isNumber(s);
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
