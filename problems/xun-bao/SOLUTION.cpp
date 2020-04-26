//////////////////////////////////////////////////////////////////////////
// by: zerotrac
using PII = pair<int, int>;

class Solution2 {
public:
    static constexpr int dirs[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    inline int special_bfs(const vector<string>& maze, PII spoint, PII epoint) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<PII> q;
        q.push(spoint);
        dist[spoint.first][spoint.second] = 0;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] != '#' && dist[nx][ny] == -1) {
                    q.emplace(nx, ny);
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }
        return dist[epoint.first][epoint.second];
    }

    inline vector<vector<int>> normal_bfs(const vector<string>& maze, PII spoint) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<PII> q;
        q.push(spoint);
        dist[spoint.first][spoint.second] = 0;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] != '#' && dist[nx][ny] == -1) {
                    q.emplace(nx, ny);
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }
        return dist;
    }

    int minimalSteps(vector<string>& maze) {
        int m = maze.size();
        int n = maze[0].size();
        vector<PII> ms;
        vector<PII> os;
        PII spoint, epoint;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (maze[i][j] == 'M') {
                    ms.emplace_back(i, j);
                }
                else if (maze[i][j] == 'O') {
                    os.emplace_back(i, j);
                }
                else if (maze[i][j] == 'S') {
                    spoint = { i, j };
                }
                else if (maze[i][j] == 'T') {
                    epoint = { i, j };
                }
            }
        }

        if (!ms.size()) {
            // no 'M'
            return special_bfs(maze, spoint, epoint);
        }
        else {
            ms.push_back(spoint);
            os.push_back(epoint);
            vector<vector<int>> value(ms.size(), vector<int>(os.size()));
            for (int i = 0; i < ms.size(); ++i) {
                vector<vector<int>> res = normal_bfs(maze, ms[i]);
                for (int j = 0; j < os.size(); ++j) {
                    value[i][j] = res[os[j].first][os[j].second];
                }
            }
            // dbg(value);
            vector<vector<int>> transit(ms.size(), vector<int>(ms.size(), -1));
            for (int i = 0; i < ms.size(); ++i) {
                for (int j = 0; j < ms.size(); ++j) {
                    for (int s = 0; s < os.size() - 1; ++s) {
                        if (value[i][s] != -1 && value[j][s] != -1) {
                            int upd = value[i][s] + value[j][s];
                            if (transit[i][j] == -1 || upd < transit[i][j]) {
                                transit[i][j] = upd;
                            }
                        }
                    }
                }
            }
            // dbg(transit);

            int mcnt = ms.size() - 1;
            int ocnt = os.size() - 1;
            vector<vector<int>> f(1 << mcnt, vector<int>(mcnt, -1));
            for (int mask = 0; mask < (1 << mcnt); ++mask) {
                for (int i = 0; i < mcnt; ++i) {
                    if (mask & (1 << i)) {
                        if (!(mask ^ (1 << i))) {
                            // start pos
                            f[mask][i] = transit[mcnt][i];
                            // for (int s = 0; s < ocnt; ++s) {
                            //     if (value[mcnt][s] != -1 && value[i][s] != -1) {
                            //         int upd = value[mcnt][s] + value[i][s];
                            //         if (f[mask][i] == -1 || upd < f[mask][i]) {
                            //             f[mask][i] = value[mcnt][s] + value[i][s];
                            //         }
                            //     }
                            // }
                        }
                        else {
                            for (int j = 0; j < mcnt; ++j) {
                                if ((mask & (1 << j)) && (i != j) && f[mask ^ (1 << i)][j] != -1 && transit[j][i] != -1) {
                                    int upd = f[mask ^ (1 << i)][j] + transit[j][i];
                                    if (f[mask][i] == -1 || upd < f[mask][i]) {
                                        f[mask][i] = upd;
                                    }
                                    // for (int s = 0; s < ocnt; ++s) {
                                    //     if (f[mask ^ (1 << i)][j] != -1 && value[j][s] != -1 && value[i][s] != -1) {
                                    //         int upd = f[mask ^ (1 << i)][j] + value[j][s] + value[i][s];
                                    //         if (f[mask][i] == -1 || upd < f[mask][i]) {
                                    //             f[mask][i] = upd;
                                    //         }
                                    //     }
                                    // }
                                }
                            }
                        }
                        // cout << "f mask i = " << mask << " " << i << " " << f[mask][i] << "\n";
                    }
                }
            }
            int ans = -1;
            for (int i = 0; i < mcnt; ++i) {
                if (f[(1 << mcnt) - 1][i] != -1 && value[i][ocnt] != -1) {
                    int upd = f[(1 << mcnt) - 1][i] + value[i][ocnt];
                    if (ans == -1 || upd < ans) {
                        ans = upd;
                    }
                }
            }
            return ans;
        }
    }
};
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minimalSteps(vector<string>& maze) {
        for (int i = 0; i < maze.size(); i++) {
            for (int j = 0; j < maze[i].size(); j++) {
                if (maze[i][j] == '#') continue;

                if (maze[i][j] == 'S') {
                    start = { i, j };
                }
                else if (maze[i][j] == 'T') {
                    target = { i, j };
                }
                else if (maze[i][j] == 'M') {
                    listM.push_back({ i, j });
                }
                else if (maze[i][j] == 'O') {
                    listO.push_back({ i, j });
                }
            }
        }

        viM = vector<bool>(listM.size(), false);

        dfs(maze, start, 0);

        if (dead) return -1;
        return ans == INT_MAX ? -1 : ans;
    }

    void dfs(vector<string>& maze, vector<int> pos, int step) {
        if (step >= ans) return;
        if (dead) return;

        if (all_of(viM.begin(), viM.end(), [](const bool a) { return a; })) {
            step += getPath(maze, pos, target);
            ans = min(ans, step);
            return;
        }

        vector<vector<int>> near;
        for (int i = 0; i < listM.size(); i++) {
            if (viM[i]) continue;

            int minStep = INT_MAX;
            for (int j = 0; j < listO.size(); j++) {
                minStep = min(minStep, getPath(maze, pos, listO[j]) + getPath(maze, listO[j], listM[i]));
            }
            near.push_back({ minStep, i });
        }
        sort(near.begin(), near.end());
        for (int k = 0; k < near.size(); k++) {
            int minStep = near[k][0];
            int i = near[k][1];
            viM[i] = true;
            dfs(maze, listM[i], step + minStep);
            viM[i] = false;

        }
    }

    int getPath(vector<string>& maze, vector<int> a, vector<int> b) {
        if (a == b) return 0;
        if (a > b) return getPath(maze, b, a);
        if (pathMap.count({ a[0], a[1], b[0], b[1] }) != 0) {
            return pathMap[{ a[0], a[1], b[0], b[1] }];
        }

        int ans = 0;
        vi = vector<vector<bool>>(maze.size(), vector<bool>(maze[0].size(), false));
        queue<vector<int>> que;
        que.push(a);
        vi[a[0]][a[1]] = true;

        while (!que.empty()) {
            ans++;
            int len = que.size();
            for (int i = 0; i < len; i++) {
                auto q = que.front();
                que.pop();

                for (auto d : dd) {
                    int dx = q[0] + d[0];
                    int dy = q[1] + d[1];
                    if (dx < 0 || dx >= maze.size()) continue;
                    if (dy < 0 || dy >= maze[0].size()) continue;
                    if (maze[dx][dy] == '#') continue;
                    if (b == vector<int>{dx, dy}) {
                        pathMap[{ a[0], a[1], b[0], b[1] }] = ans;
                        return ans;
                    }
                    if (vi[dx][dy]) continue;
                    vi[dx][dy] = true;
                    que.push({ dx, dy });
                }
            }
        }
        dead = true;
        return -1;
    }

private:
    int ans = INT_MAX;
    vector<int> start;
    vector<int> target;
    vector<bool> viM;
    vector<vector<bool>> vi;
    vector<vector<int>> listM;
    vector<vector<int>> listO;
    map<vector<int>, int> pathMap;
    bool dead = false;

    vector<vector<int>> dd = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<string>& maze)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution2 sln;
    return sln.minimalSteps(maze);
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
