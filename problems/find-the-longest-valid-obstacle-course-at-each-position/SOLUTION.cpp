
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> ans(obstacles.size(), 0);
        map<int, int> mp;
        ans[0] = 1;
        mp[ans[0]] = obstacles[0];

        for (int i = 1; i < obstacles.size(); i++) {
            int hi = i;
            int lo = 0;
            while (hi > lo) {
                int mid = lo + (hi - lo) / 2;
                auto it = mp.lower_bound(mid);
                if (it != mp.end() && it->second <= obstacles[i]) {
                    lo = mid + 1;
                }
                else {
                    hi = mid;
                }
            }
            ans[i] = lo;
            if (mp.find(ans[i]) == mp.end()) {
                mp[ans[i]] = obstacles[i];
            }
            for (auto it = mp.begin(); it != mp.end(); it++) {
                if (it->first > ans[i]) break;
                it->second = min(it->second, obstacles[i]);
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& obstacles)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.longestObstacleCourseAtEachPosition(obstacles);
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
