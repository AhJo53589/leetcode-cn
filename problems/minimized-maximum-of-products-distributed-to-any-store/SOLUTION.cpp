
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int lo = 1;
        int hi = INT_MAX;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(n, quantities, mid)) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        return lo;
    }

    int check(int n, vector<int>& quantities, int mid) {
        int cnt = 0;
        for (auto& q : quantities) {
            cnt += (q / mid) + ((q % mid) != 0);
        }
        return cnt > n;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, vector<int>& quantities)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.minimizedMaximum(n, quantities);
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
