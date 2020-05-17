
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<string>dp(target + 1);
        dp[0] = "";
        for (int j = 1; j <= target; j++) {
            dp[j] = "0";
        }
        for (int i = 0; i < cost.size(); i++) {
            for (int j = cost[i]; j <= target; j++) {
                dp[j] = mmin(dp[j], add(dp[j - cost[i]], i + 1));
            }
        }
        return dp[target];
    }

    string mmin(string a, string b) {
        if (a.size() > b.size()) return a;
        else if (b.size() > a.size()) return b;
        return a > b ? a : b;
    }

    string add(string a, int b) {
        if (a == "0") return "0";
        string c = to_string(b);
        return c + a;
    }
};


//////////////////////////////////////////////////////////////////////////
string _solution_run(vector<int>& cost, int target)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(cost);
    cout << target << endl;
    Solution sln;
    return sln.largestNumber(cost, target);
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
