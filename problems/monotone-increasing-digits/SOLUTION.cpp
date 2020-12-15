
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string str = to_string(N);
        int pos = INT_MAX;
        for (int i = str.size() - 2; i >= 0; i--) {
            pos = (str[i] > str[i + 1]) ? i : pos;
            pos = (pos == i + 1 && str[i] == str[i + 1]) ? i : pos;
        }
        for (int i = 0; i < str.size(); i++) {
            str[i] = (i > pos) ? '9' : (i == pos) ? (char)(str[i] - 1) : str[i];
        }
        return stoi(str);
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int N)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.monotoneIncreasingDigits(N);
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
