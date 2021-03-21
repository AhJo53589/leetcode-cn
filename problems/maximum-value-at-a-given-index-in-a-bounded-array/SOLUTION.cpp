
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int lo = 1;
        int hi = maxSum + 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (calcSum(mid, n, index) <= maxSum) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }

        return lo - 1;
    }

    long long calcSum(int x, int n, int index) {
        long long sum = n - 1 + x;

        long long left = min(index, x - 1);
        sum += (1LL * ((x - left) + (x - 1))) * left / 2;

        long long right = min(n - index - 1, x - 1);
        sum += (1LL * ((x - 1) + (x - right))) * right / 2;

        sum = sum - left - right;
        //cout << x << ", " << sum << endl;
        return sum;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, int index, int maxSum)
{
    int caseNo = -1;
    static int caseCnt = 0;
    if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.maxValue(n, index, maxSum);
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
