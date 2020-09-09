
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numWays(string s) {
        vector<int> v;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') continue;
            v.push_back(i);
        }
        if (v.size() % 3 != 0) return 0;
        
        if (v.size() == 0) {
            return calc(s.size() - 2);
        }
        
        int a = v.size() / 3 - 1;
        int b = v.size() / 3;
        int c = v.size() / 3 * 2 - 1;
        int d = v.size() / 3 * 2;
        int ab = v[b] - v[a];
        int cd = v[d] - v[c];
        return (int)multi(ab, cd, mod);
    }
    
    int calc(int n) {
        return (int)multi((1 + n), n, mod) / 2;
    }
    
    int multi(int m, int n, int mod) {
        int ans = 0;
        while (n) {
            if (n & 1) {
                ans += m;
            }
            m = (m + m) % mod;
            m %= mod;
            ans %= mod;
            n >>= 1;
        }
        return ans;
    }
    
    int mod = 1e9 + 7;
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.numWays(s);
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
