
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minimumSwitchingTimes(vector<vector<int>>& source, vector<vector<int>>& target) {
        unordered_map<int, int> sc;
        for (auto& v : source) {
            for (auto& n : v) {
                sc[n]++;
            }
        }

        unordered_map<int, int> tc;
        for (auto& v : target) {
            for (auto& n : v) {
                tc[n]++;
            }
        }

        int ans = 0;
        for (auto it = tc.begin(); it != tc.end(); it++) {
            ans += max(it->second - sc[it->first], 0);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& source, vector<vector<int>>& target)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.minimumSwitchingTimes(source, target);
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
