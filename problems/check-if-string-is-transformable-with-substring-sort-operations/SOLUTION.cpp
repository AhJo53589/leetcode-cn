
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isTransformable(string s, string t) {
        vector<vector<int>> data(10, vector<int>());
        vector<int> pos(10, 0);

        for (int i = 0; i < s.size(); i++) {
            data[s[i] - '0'].push_back(i);
        }

        for (int i = 0; i < t.size(); i++) {
            int p = t[i] - '0';
            if (pos[p] >= data[p].size()) return false;

            for (int j = 0; j < p; j++) {
                if (pos[j] < data[j].size() && data[j][pos[j]] < data[p][pos[p]]) return false;
            }

            pos[p]++;
        }
        return true;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string s, string t)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << "s = " << s << endl << "t = " << t << endl;
    Solution sln;
    return sln.isTransformable(s, t);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//    return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
