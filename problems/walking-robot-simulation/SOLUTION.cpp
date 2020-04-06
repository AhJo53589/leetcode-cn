//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles)
    {
        int ans = 0;
        unordered_map<int, unordered_set<int>> ob;
        for (auto& p : obstacles)
        {
            ob[p[0]].insert(p[1]);
        }

        vector<vector<int>> dd = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
        int dir = 0;
        vector<int> pos = { 0,0 };

        for (auto& c : commands)
        {
            dir = (c == -2) ? (dir + 4 - 1) % 4 : dir;
            dir = (c == -1) ? (dir + 1) % 4 : dir;
            for (int i = 0; i < c; i++)
            {
                vector<int> next = { pos[0] + dd[dir][0], pos[1] + dd[dir][1] };
                if (ob[next[0]].count(next[1]) != 0) break;
                pos = next;
                ans = max(ans, pos[0] * pos[0] + pos[1] * pos[1]);
            }
        }

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles)
    {
        int ans = 0;
        set<vector<int>> ob;
        for (auto& p : obstacles)
        {
            ob.insert(p);
        }

        vector<vector<int>> dd = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
        int dir = 0;
        vector<int> pos = { 0,0 };

        for (auto& c : commands)
        {
            dir = (c == -2) ? (dir + 4 - 1) % 4 : dir;
            dir = (c == -1) ? (dir + 1) % 4 : dir;
            for (int i = 0; i < c; i++)
            {
                vector<int> next = { pos[0] + dd[dir][0], pos[1] + dd[dir][1] };
                if (ob.count(next) != 0) break;
                pos = next;
                ans = max(ans, pos[0] * pos[0] + pos[1] * pos[1]);
            }
        }

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& commands, vector<vector<int>>& obstacles)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.robotSim(commands, obstacles);
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
