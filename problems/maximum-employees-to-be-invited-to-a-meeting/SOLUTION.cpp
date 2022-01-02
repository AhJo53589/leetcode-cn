
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int ans = 0;

        unordered_map<int, vector<int>> uf;
        unordered_map<int, int> vi;
        vector<int> endPoint;
        for (int i = 0; i < favorite.size(); i++) {
            if (favorite[favorite[i]] == i) {
                endPoint.push_back(i);
            }
            else {
                uf[favorite[i]].push_back(i);
            }
        }

        for (int i = 0; i < endPoint.size(); i++) {
            ans += dfs(endPoint[i], uf, vi);
        }

        for (int i = 0; i < favorite.size(); i++) {
            if (vi[i] == -1) continue;
            ans = max(ans, circle(i, favorite, vi));
        }
        return ans;
    }

    int dfs(int cur, unordered_map<int, vector<int>>& uf, unordered_map<int, int>& vi) {
        int cnt = 0;
        for (int i = 0; i < uf[cur].size(); i++) {
            cnt = max(cnt, dfs(uf[cur][i], uf, vi));
        }
        vi[cur] = -1;
        return cnt + 1;
    }

    int circle(int idx_in, vector<int>& favorite, unordered_map<int, int>& vi) {
        int cnt = 0;
        int cur = idx_in;
        int step = 0;
        int flag = -2;
        while (flag == -2) {
            vi[cur] = ++step;
            int next = favorite[cur];
            flag = (vi[next] == -1) ? -1 : flag;
            flag = (vi[next] > 0) ? next : flag;
            cur = next;
        }

        if (flag != -1) {
            cnt = step - vi[flag] + 1;
        }

        cur = idx_in;
        while (vi[cur] != -1) {
            vi[cur] = -1;
            cur = favorite[cur];
        }

        return cnt;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& favorite)
{
    printVectorT(favorite);
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.maximumInvitations(favorite);
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
