
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool composeCube(vector<vector<string>>& shapes) {
        int ans = 0;
        vector<int> seq = { 0,1,2,3,4,5 };
        do {

        } while (next_permutation(seq.begin(), seq.end()));


        return false;
    }

    bool check(vector<vector<string>>& shapes, vector<int>& seq, vector<int>& dir) {
        
    }

    int getLine(vector<string>& shape, vector<int>& dir, int idx) {
        int line = 0;
        int index = border[dir][idx];
        for (int i = 0; i < shape.size(); i++) {
            if (index == 0) {
                line += (shape.front()[i] == '1') ? (1 << i) : 0;
            }
            else if (index == 1) {
                line += (shape[i].back() == '1') ? (1 << i) : 0;
            }
            else if (index == 2) {
                line += (shape.back()[(int)shape.size() - i - 1] == '1') ? (1 << i) : 0;
            }
            else if (index == 3) {
                line += (shape[(int)shape.size() - i - 1].front() == '1') ? (1 << i) : 0;
            }
        }
        return line;
    }

    bool checkLine(vector<vector<string>>& shapes, int a, int b) {
        int x = a ^ b;
        for (int i = 0; i < shapes[0].size(); i++) {
            int y = (1 << i);
            if (x & y != 1) return false;
        }
        return true;
    }

private:
    vector<int> adjBorder = { 22,17,4,11,2,16,12,8,7,15,23,3,6,19,20,9,5,1,21,13,14,18,0,10 };
    vector<vector<int>> border = { {0,1,2,3}, {1,2,3,0}, {2,3,0,1}, {3,0,1,2} };

    //vector<vector<int>> adjPoint = { {0,17,21}, {1,4,16}, {2,7,11}, {3,10,22}, {5,12,19}, {6,15,8}, {9,14,23}, {13,18,20} };
    //vector<vector<int>> point = {}
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<vector<string>>& shapes)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.composeCube(shapes);
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
