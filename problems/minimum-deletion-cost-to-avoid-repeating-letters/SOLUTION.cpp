
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int ans = 0;
        for (int i = 0; i < s.size();) {
            for (int j = i; j < s.size(); j++) {
                if (j != s.size() - 1 && s[i] == s[j + 1]) continue;
                if (i != j) {
                    ans += del(s, i, j, cost);
                }
                i = j + 1;
            }
        }
        return ans;
    }

    int del(string& s, int l, int r, vector<int>& cost) {
        int sum = 0;
        int m = cost[l];
        for (int i = l; i <= r; i++) {
            sum += cost[i];
            m = max(m, cost[i]);
        }
        return sum - m;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s, vector<int>& cost)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.minCost(s, cost);
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
