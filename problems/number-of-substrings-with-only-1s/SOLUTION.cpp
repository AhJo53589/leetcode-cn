
//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
    int numSub(string s) {
        int mod = 1000000007;
        int ans = 0, cur = 0;
        for (char ch : s) {
            if (ch == '1') {
                ++cur;
                ans += cur;
                if (ans >= mod) {
                    ans -= mod;
                }
            }
            else {
                cur = 0;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int numSub(string s) {
        s.insert(0, "0");
        s += "0";
        int ans = 0;
        int i = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '0') {
                ans += getCount(j - 1 - i);
                ans %= mod;
                i = j;
            }
        }
        return ans;
    }

    int getCount(int n) {
        int cnt = 0;
        while (n > 0) {
            cnt += n;
            cnt %= mod;
            n--;
        }
        return cnt;
    }

private:
    const int mod = 1e9 + 7;
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    //printVectorT(s);
    Solution sln;
    return sln.numSub(s);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//    return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
