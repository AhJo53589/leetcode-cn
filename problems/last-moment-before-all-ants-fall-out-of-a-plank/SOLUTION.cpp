
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ret = 0;
        for (auto& a : left) {
            int t = a;
            ret = max(ret, t);
        }
        for (auto& a : right) {
            ret = max(ret, n - a);
        }
        return ret;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, vector<int>& left, vector<int>& right)
{
	int caseNo = 6;
	static int caseCnt = 0;
	if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.getLastMoment(n, left, right);
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
