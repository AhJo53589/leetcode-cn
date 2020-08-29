
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3) return n - 1;
        int a = n / 3, b = n % 3;
        int mod = 1e9 + 7;
        if (b == 0) return pow1(3, a, mod, 1);
        if (b == 1) return pow1(3, a - 1, mod, 4);
        return pow1(3, a, mod, 2);
    }

    long long pow1(long long a, long long n, long long mod, int mul) {
        long long res = 1;
        while (n > 0) {
            if (n & 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
            n >>= 1;
        }
        res = (res * mul) % mod;
        return (int)(res);
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.cuttingRope(n);
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
