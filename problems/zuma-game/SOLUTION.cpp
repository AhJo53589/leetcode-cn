
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findMinStep(string board, string hand) {
        cnt = hand.size();
        for (auto c : hand) {
            h[c - 'A']++;
        }

        dfs(board, 0);
        return ans == INT_MAX ? -1 : ans;
    }

    void dfs(string board, int step) {
        shoot(board);

        if (board.empty()) {
            ans = min(ans, step);
        }
        if (step == cnt) return;
        if (step >= ans) return;

        set<pair<int, char>> ins;
        for (int i = 0; i < board.size(); i++) {
            int t = board[i] - 'A';
            if (i == 0 || board[i] != board[i - 1]) {
                if (h[t] != 0) {
                    ins.insert({ i, 'A' + t });
                }
            }
            if (i != 0 && board[i] == board[i - 1]) {
                for (int j = 0; j < h.size(); j++) {
                    if (j == t || h[j] == 0) continue;
                    ins.insert({ i, 'A' + j });
                }
            }
        }

        for (auto[i, c] : ins) {
            h[c - 'A']--;
            board.insert(i, 1, c);
            dfs(board, step + 1);
            board.erase(i, 1);
            h[c - 'A']++;
        }
    }

    void shoot(string& board) {
        for (int i = 0; i < (int)board.size() - 2; i++) {
            int j = i + 1;
            while (j < board.size() && board[i] == board[j]) j++;
            if (j - i < 3) {
                i = j - 1;
                continue;
            }
            board.erase(i, j - i);
            shoot(board);
            break;
        }
    }

private:
    int ans = INT_MAX;
    int cnt = 0;
    vector<int> h = vector<int>(26, 0);
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string board, string hand)
{
    //int caseNo = 6;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << board << endl;
    cout << hand << endl;
    Solution sln;
    return sln.findMinStep(board, hand);
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
