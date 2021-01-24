
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string maximumTime(string time) {
        if (time[0] == '?') {
            time[0] = ((time[1] < '4' && time[1] >= '0') || time[1] == '?') ? '2' : '1';
        }
        if (time[1] == '?') {
            time[1] = (time[0] != '2') ? '9' : '3';
        }
        if (time[3] == '?') {
            time[3] = '5';
        }
        if (time[4] == '?') {
            time[4] = '9';
        }
        return time;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string time)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.maximumTime(time);
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
