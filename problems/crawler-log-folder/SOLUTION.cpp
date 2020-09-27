
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for (auto s : logs) {
            if (s == "./") continue;
            ans += (s == "../") ? -1 : 1;
            ans = max(ans, 0);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<string>& logs)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.minOperations(logs);
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
