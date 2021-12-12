
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int countPoints(string rings) {
        unordered_set<int> ans;
        unordered_map<char, int> change = { {'R', 0}, {'G', 1}, {'B', 2} };
        vector<vector<int>> t(10, vector<int>(3, 0));
        for (int i = 0; i < rings.size(); i += 2) {
            int idx = rings[i + 1] - '0';
            t[idx][change[rings[i]]]++;
            if ((t[idx][0] >= 1) && (t[idx][1] >= 1) && (t[idx][2] >= 1)) {
                ans.insert(idx);
            }
        }
        return ans.size();
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string rings)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};
    cout << rings << endl;
    Solution sln;
    return sln.countPoints(rings);
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
