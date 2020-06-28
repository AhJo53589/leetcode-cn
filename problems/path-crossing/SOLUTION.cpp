
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isPathCrossing(string path) {
        set<vector<int>> vi;
        unordered_map<char, vector<int>> dd;
        dd['N'] = { -1, 0 };
        dd['S'] = { 1, 0 };
        dd['E'] = { 0, 1 };
        dd['W'] = { 0, -1 };

        vector<int> pos = { 0, 0 };
        for (auto c : path) {
            vi.insert(pos);

            auto d = dd[c];
            pos[0] += d[0];
            pos[1] += d[1];
            if (vi.count(pos) != 0) return true;
        }
        return false;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string path)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.isPathCrossing(path);
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
