
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        int na = (numerator < 0) ? -1 : 1;
        int nb = (denominator < 0) ? -1 : 1;
        long long lln = 1LL * numerator * na;
        long long lld = 1LL * denominator * nb;

        string ans = (na * nb == -1) ? "-" : "";
        ans += to_string(lln / lld);
        lln %= lld;
        lln *= 10;

        ans = (lln != 0) ? ans + '.' : ans;
        unordered_map<long long, int> um;
        while (lln != 0) {
            if (um.find(lln) != um.end()) {
                ans.insert(um[lln], 1, '(');
                ans += ')';
                break;
            }

            um[lln] = (int)ans.size();
            ans += to_string(lln / lld);
            lln %= lld;
            lln *= 10;
        }
        
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(int numerator, int denominator)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.fractionToDecimal(numerator, denominator);
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
