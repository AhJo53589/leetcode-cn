
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> getSame(string& board, int idx)
    {
        if (idx < 0 || idx >= board.size()) return {};
        int left = idx;
        int right = idx;
        while (left > 0 && board[left - 1] == board[left]) --left;
        while (right < board.size() - 1 && board[right + 1] == board[right]) ++right;
        return { left, right };
    }

    void shoot(string &board, int idx)
    {
        auto rg = getSame(board, idx);
        if (rg.empty()) return;
        if (rg[1] - rg[0] + 1 < 3) return;
        board = board.substr(0, rg[0]) + board.substr(rg[1] + 1);
        shoot(board, max(rg[0] - 1, 0));
    }

    void findMinStep(string board, unordered_map<char, int>& cntHand, int step, int& ans)
    {
        if (step >= ans) return;
        if (board.empty())
        {
            ans = min(ans, step);
            return;
        }

        for (int i = 0; i < board.size(); i++)
        {
            if (i != 0 && board[i] == board[i - 1]) continue;
            set<string> insertList;
            auto rg = getSame(board, i);
            if (rg[1] - rg[0] == 0)
            {
                insertList.insert({ board[i],board[i] });
            }
            else
            {
                insertList.insert({ board[i] });

                vector<int> flag(2, 0);
                char c = board[i];
                for (int d = 0; d <= 1; d++)
                {
                    int td = d * 2 - 1;
                    for (int j = i; j >= 0 && j < board.size(); j += td)
                    {
                        if (td == 1 && j == 0) continue;
                        if (td == -1 && j == board.size() - 1) continue;
                        flag[d] += (board[j - td] == c && board[j] != c) ? 1 : 0;
                        flag[d] += (board[j - td] != c && board[j] == c) ? 1 : 0;
                        if (flag[d] <= 2) continue;
                        insertList.insert({ board[j] });
                    }
                }
            }
            for (auto& item : insertList)
            {
                if (cntHand[item[0]] < item.size()) continue;

                cntHand[item[0]] -= item.size();
                string newBoard = board;
                newBoard = newBoard.insert(i + 1, item);
                shoot(newBoard, i);
                findMinStep(newBoard, cntHand, step + item.size(), ans);
                cntHand[item[0]] += item.size();
            }
        }
    }

    int findMinStep(string board, string hand) 
    {
        unordered_map<char, int> cntBoard;
        unordered_map<char, int> cntHand;
        for (auto& c : board)
        {
            cntBoard[c]++;
        }
        for (auto& c : hand)
        {
            cntHand[c]++;
        }
        for (auto& p : cntBoard)
        {
            if (p.second < 3 && cntHand[p.first] + p.second < 3) return -1;
        }

        int ans = INT_MAX;
        findMinStep(board, cntHand, 0, ans);
        return (ans == INT_MAX) ? -1 : ans;
    }
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
