
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string replaceSpaces(string S, int length) {
        int writePos = S.size() - 1;
        for (int i = 0; i < length; i++) {
            int readPos = length - 1 - i;
            if (S[readPos] != ' ') {
                S[writePos--] = S[readPos];
            }
            else {
                S[writePos--] = '0';
                S[writePos--] = '2';
                S[writePos--] = '%';
            }
        }

        if (writePos >= 0) {
            S = S.substr(writePos + 1, S.size() - writePos - 1);
        }
        
        return S;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string S, int length)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.replaceSpaces(S, length);
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
