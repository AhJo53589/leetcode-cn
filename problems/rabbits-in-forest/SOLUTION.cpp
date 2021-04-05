
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans = 0;
        unordered_map<int, int> cnt;
        for (auto n : answers) {
            ans += (n == 0);
            cnt[n]++;
        }
        cnt.erase(0);

        for (auto [k, v] : cnt) {
            ans += (v / (k + 1) + (v % (k + 1) != 0)) * (k + 1);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& answers)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.numRabbits(answers);
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
