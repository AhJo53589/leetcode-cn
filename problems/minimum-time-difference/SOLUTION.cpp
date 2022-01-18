
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> s(timePoints.size(), 0);
        for (int i = 0; i < s.size(); i++) {
            int hour = (timePoints[i][0] - '0') * 10 + (timePoints[i][1] - '0');
            int min = (timePoints[i][3] - '0') * 10 + (timePoints[i][4] - '0');
            s[i] = hour * 60 + min;
        }

        int ans = INT_MAX;
        int day = 1 * 24 * 60;
        sort(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++) {
            int cur = s[i];
            int next = (i + 1 != s.size()) ? s[i + 1] : s[0];
            ans = min(abs(cur - next), ans);
            ans = min(day - abs((cur - next)), ans);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<string>& timePoints)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.findMinDifference(timePoints);
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
