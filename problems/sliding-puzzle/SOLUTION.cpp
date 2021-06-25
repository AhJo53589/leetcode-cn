
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> dd = { { 1, 3 }, { 0, 2, 4 }, { 1, 5 }, { 0, 4 }, { 1, 3, 5 }, { 2, 4 } };
        bitset<1000000> vi;
        int target = 54321;

        int start = 0;
        for (int i = board.size() - 1; ~i; i--) {
            for (int j = board[i].size() - 1; ~j; j--) {
                start *= 10;
                start += board[i][j];
            }
        }
        if (start == target) return 0;

        int ans = 0;
        queue<int> que;
        que.push(start);
        vi[start] = 1;

        while (!que.empty()) {
            for (int step = que.size() - 1; ~step; step--) {
                auto q = que.front();
                que.pop();

                int i = findZero(q);
                for (auto j : dd[i]) {
                    int next = swapDigit(q, i, j);
                    if (next == target) return ans + 1;
                    if (vi[next]) continue;
                    vi[next] = 1;
                    que.push(next);
                }
            }
            ans++;
        }

        return -1;
    }

    int findZero(int num) {
        for (int i = 0; i < 6; i++) {
            if (num % 10 == 0) return i;
            num /= 10;
        }
        return 6;
    }

    int swapDigit(int num, int i, int j) {
        int a = (num / (int)pow(10, i)) % 10;
        int b = (num / (int)pow(10, j)) % 10;
        return num + a * pow(10, j) + b * pow(10, i) - a * pow(10, i) - b * pow(10, j);
    }

    //void test() {
    //    int a = 54321;
    //    for (int i = 0; i < 6; i++) {
    //        for (int j = i + 1; j < 6; j++) {
    //            int b = swapDigit(a, i, j);
    //            cout << "[" << i << ", " << j << "] = " << setw(6) << setfill('0') << b << endl;
    //            cout << findZero(b) << endl;
    //        }
    //    }
    //}
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& board)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.slidingPuzzle(board);
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
