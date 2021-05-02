
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int ans = 0;
        unordered_map<int, int> dic;
        for (auto& w : wall) {
            for (int i = 1; i < w.size(); i++) {
                dic[w[i - 1]]++;
                ans = max(ans, dic[w[i - 1]]);
                w[i] += w[i - 1];
            }
        }
        return (int)wall.size() - ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& wall)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.leastBricks(wall);
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
