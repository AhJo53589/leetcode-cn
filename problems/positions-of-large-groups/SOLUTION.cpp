
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        s += '-';
        pair<char, int> start = { s[0], 0 };

        vector<vector<int>> ans;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == start.first) continue;
            if (i - start.second >= 3) {
                ans.push_back({ start.second, i - 1 });
            }
            start = { s[i], i };
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(string s)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.largeGroupPositions(s);
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
