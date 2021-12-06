
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string truncateSentence(string s, int k) {
        stringstream ss(s);
        string ans;
        string temp;
        while (k-- > 0 && ss >> temp) {
            ans += temp + " ";
        }
        ans.pop_back();
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string s, int k)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.truncateSentence(s, k);
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
