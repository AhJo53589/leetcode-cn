
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string longestDiverseString(int a, int b, int c)
    {
        string ans;
        vector<vector<int>> cnt = { {a, 0}, {b, 1}, {c, 2} };

        while (true)
        {
            sort(cnt.rbegin(), cnt.rend());
            if (cnt[0][0] < 2) break;
            if (cnt[1][0] < 1) break;

            ans += ('a' + cnt[0][1]);
            ans += ('a' + cnt[0][1]);
            if (cnt[0][0] <= cnt[1][0] + cnt[2][0] && cnt[1][0] > 1)
            {
                ans += ('a' + cnt[1][1]);
                cnt[1][0] -= 1;
            }
            ans += ('a' + cnt[1][1]);
            cnt[1][0] -= 1;
            cnt[0][0] -= 2;
        }

        sort(cnt.rbegin(), cnt.rend());
        for (int i = 0; i < cnt.size(); i++)
        {
            if (cnt[i][0] == 0) return ans;
            ans += ('a' + cnt[i][1]);
            if (cnt[i][0] != 1)
            {
                ans += ('a' + cnt[i][1]);
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(int a, int b, int c)
{
    int caseNo = -1;
    static int caseCnt = 0;
    if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.longestDiverseString(a, b, c);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//    return {};
//}

//////////////////////////////////////////////////////////////////////////
#define USE_CHECKANSWER_CUSTOM
void _checkAnswer_custom(string& ans, TestCases& tc)
{
    string answer = tc.get<string>();
    vector<int> cnt_ans(3, 0);
    vector<int> cnt_answer(3, 0);
    bool check = true;
    for (int i = 0; i < ans.size(); i++)
    {
        if (i - 2 >= 0 && ans[i - 2] == ans[i] && ans[i - 1] == ans[i])
        {
            check = false;
            break;
        }
        cnt_ans[ans[i] - 'a']++;
    }
    for (int i = 0; i < answer.size(); i++)
    {
        cnt_answer[answer[i] - 'a']++;
    }
    if (cnt_ans != cnt_answer)
    {
        check = false;
    }
    answer = check ? ans : answer;
    std::cout << checkAnswer<decltype(ans)>(ans, answer) << std::endl;
}