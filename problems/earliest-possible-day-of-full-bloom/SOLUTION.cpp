
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<vector<int>> v;
        for (int i = 0; i < plantTime.size(); i++) {
            v.push_back({ plantTime[i], growTime[i] });
        }
        sort(v.begin(), v.end(), [](auto& a, auto& b) {
            return (a[1] == b[1]) ? a[0] < b[0] : a[1] > b[1];
        });

        int cost = 0;
        int ans = 0;
        for (int i = 0; i < v.size(); i++) {
            cost += v[i][0];
            ans = max(ans, cost + v[i][1]);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& plantTime, vector<int>& growTime)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.earliestFullBloom(plantTime, growTime);
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
