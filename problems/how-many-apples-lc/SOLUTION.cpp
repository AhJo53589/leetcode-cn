


//////////////////////////////////////////////////////////////////////////
const int MOD = 1e9 + 7;
class Solution {
public:
	long long power_mod(long long a, int n) {
		long long ret = 1;
		for (; n; n >>= 1) {
			if (n & 1) ret = ret * a % MOD;
			a = a * a % MOD;
		}
		return ret;
	}
	int findNum(int n, int k) {
		int u = n / gcd(n, k);
		int ret = power_mod(u, n) * n % MOD;
		ret = (ret + MOD + k - n) % MOD;
		return ret;
	}
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, int k)
{
	return findNum(n,k);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

