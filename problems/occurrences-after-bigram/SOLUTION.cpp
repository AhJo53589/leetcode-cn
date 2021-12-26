
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> ans;

        stringstream ss(text);
        string pre = "";
        string cur = "";
        bool flag = false;
        while (ss >> cur) {
            if (flag) {
                ans.push_back(cur);
            }
            flag = (pre == first && cur == second);
            pre = cur;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<string> _solution_run(string text, string first, string second)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.findOcurrences(text, first, second);
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
