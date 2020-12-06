
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string interpret(string command) {
        string ans;
        for (int i = 0; i < command.size(); i++) {
            if (command[i] == 'G') {
                ans += 'G';
            }
            else if (command[i] == '(') {
                if (command[i + 1] == ')') {
                    ans += 'o';
                    i += 1;
                }
                else {
                    ans += "al";
                    i += 3;
                }
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string command)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.interpret(command);
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
