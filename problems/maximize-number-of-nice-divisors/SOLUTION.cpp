
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxNiceDivisors(int primeFactors) {
        if (primeFactors == 1) return 1;

        long long mod = 1e9 + 7;
        int last = (primeFactors % 3 == 1) ? 4 : (primeFactors % 3 == 2) ? 2 : 0;
        primeFactors -= last;
        int n = primeFactors / 3;

        long long ans = qpow(3, n, mod);
        if (last != 0) {
            ans = qmul(ans, last, mod);
        }
        return ans;
    }

    long long qmul(long long x, long long y, long long mod)
    {
        long long ret = 0;
        while (y) {
            if (y & 1)
                ret = (ret + x) % mod;
            x = x * 2 % mod;
            y >>= 1;
        }
        return ret;
    }

    long long qpow(long long a, long long n, long long mod)
    {
        long long ret = 1;
        while (n)
        {
            if (n & 1) ret = qmul(ret, a, mod);
            a = qmul(a, a, mod);
            n >>= 1;
        }
        return ret;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int primeFactors)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << primeFactors << endl;

    Solution sln;
    return sln.maxNiceDivisors(primeFactors);
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
