
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int concatenatedBinary(int n) {
        const long long mod = 1e9 + 7;

        string s;
        string t = "0";
        for (int i = 1; i <= n; i++) {
            addOne(t);
            s += t;
        }
        long long ans = 0;
        for (auto c : s) {
            ans *= 2;
            ans += (c == '1');
            ans %= mod;
        }
        return ans;
    }

    void addOne(string& s) {
        bool flag = true;
        for (int i = s.size() - 1; i >= 0 && flag; i--) {
            flag &= (s[i] == '1');
            s[i] = (s[i] == '1') ? '0' : '1';
        }
        if (flag) {
            s += '0';
            s.front() = '1';
        }
    }
};


//string intToA(int n, int radix) {
//    string ans = "";
//    do {
//        int t = n % radix;
//        if (t >= 0 && t <= 9) {
//            ans += t + '0';
//        }
//        else {
//            ans += t - 10 + 'a';
//        }
//        n /= radix;
//    } while (n != 0);
//    reverse(ans.begin(), ans.end());
//    return ans;
//}

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << n << endl;
    Solution sln;
    return sln.concatenatedBinary(n);
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
