
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long _sum = 0;
        for (auto& b : batteries) {
            _sum += b;
        }
        sort(batteries.rbegin(), batteries.rend());
        for (auto& b : batteries) {
            if (b > _sum / n) {
                n--;
                _sum -= b;
                continue;
            }
            return _sum / n;
        }
        return 0;
    }
};

//////////////////////////////////////////////////////////////////////////
long _solution_run(int n, vector<int>& batteries)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.maxRunTime(n, batteries);
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
