
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    char firstUniqChar(string s) {
        vector<int> dic(26, 0);

        for (auto c : s) {
            dic[c - 'a']++;
        }

        for (auto c : s) {
            if (dic[c - 'a'] == 1) return c;
        }

        return ' ';
    }
};

//////////////////////////////////////////////////////////////////////////
char _solution_run(string s)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.firstUniqChar(s);
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
