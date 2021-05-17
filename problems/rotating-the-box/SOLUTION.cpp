
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        vector<vector<char>> ans = vector<vector<char>>(box[0].size(), vector<char>(box.size()));
        for (int i = 0; i < box[0].size(); i++) {
            for (int j = 0; j < box.size(); j++) {
                int x = (int)box.size() - j - 1;
                ans[i][x] = box[j][i];
            }
        }

        for (int j = 0; j < ans[0].size(); j++) {
            vector<int> emptyPos;
            int emptyIdx = 0;
            for (int i = (int)ans.size() - 1; i >= 0; i--) {
                if (ans[i][j] == '.') {
                    emptyPos.push_back(i);
                }
                else if (ans[i][j] == '#' && emptyIdx < emptyPos.size()) {
                    ans[emptyPos[emptyIdx]][j] = '#';
                    emptyIdx++;
                    ans[i][j] = '.';
                    emptyPos.push_back(i);
                }
                else {
                    emptyPos.clear();
                    emptyIdx = 0;
                }
            }
        }

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<vector<char>> _solution_run(vector<vector<char>>& box)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.rotateTheBox(box);
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
