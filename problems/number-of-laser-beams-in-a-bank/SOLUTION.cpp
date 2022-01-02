
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int pre = 0;
        for (int i = 0; i < bank.size(); i++) {
            int cur = calc(bank[i]);
            if (cur == 0) continue;

            ans += cur * pre;
            pre = (cur != 0) ? cur : pre;
        }
        return ans;
    }

    int calc(string& s) {
        int cnt = 0;
        for (auto c : s) {
            cnt += c - '0';
        }
        return cnt;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<string>& bank)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.numberOfBeams(bank);
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
