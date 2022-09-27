
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> ballGame(int num, vector<string>& plate) {
        vector<vector<int>> start;
        for (int x = 1; x < plate.size() - 1; x++) {
            findStart(plate, x, 0, 0, start);
            findStart(plate, x, plate[0].size() - 1, 2, start);
        }
        for (int y = 1; y < plate[0].size() - 1; y++) {
            findStart(plate, 0, y, 1, start);
            findStart(plate, plate.size() - 1, y, 3, start);
        }

        vector<vector<int>> ans;
        for (auto s : start) {
            if (dfs(num, plate, s[0], s[1], s[2], s[3])) {
                ans.push_back({ s[0], s[1] });
            }
        }
        return ans;
    }

   void findStart(vector<string>& plate, int x, int y, int dir, vector<vector<int>>& start) {
       if (plate[x][y] != '.') return;
       start.push_back({ x, y, dir, 0 });
   }

   int dfs(int num, vector<string>& plate, int x, int y, int dir, int step) {
       if (++step > num) return false;

       int dx = x + dd[dir][0];
       int dy = y + dd[dir][1];
       
       if (dx < 0 || dx >= plate.size()) return false;
       if (dy < 0 || dy >= plate[0].size()) return false;
       if (plate[dx][dy] == 'O') return true;

       dir = (plate[dx][dy] == 'W') ? (dir + 3) % 4 : dir;
       dir = (plate[dx][dy] == 'E') ? (dir + 1) % 4 : dir;
       if (step <= vi[dx][dy][dir]) return true;

       vi[dx][dy][dir] = step;
       if (!dfs(num, plate, dx, dy, dir, step)) {
           vi[dx][dy][dir] = 0;
           return false;
       }
       return true;
   }

private:
    vector<vector<int>> dd = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; // → ↓ ← ↑
    int vi[1010][1010][4];
};


//class Solution {
//public:
//    vector<vector<int>> ballGame(int num, vector<string>& plate) {
//        // [0] = x, [1] = y, [2] = dir
//        vector<vector<vector<int>>> vi(plate.size(), vector<vector<int>>(plate[0].size(), vector<int>(4, num + 1)));
//        queue<vector<int>> que;
//
//        for (int x = 0; x < plate.size(); x++) {
//            for (int y = 0; y < plate[x].size(); y++) {
//                if (plate[x][y] == 'O') {
//                    for (int d = 0; d < dd.size(); d++) {
//                        que.push({x, y, d, 0});
//                        vi[x][y][d] = 0;
//                    }
//                }
//            }
//        }
//        
//        while (!que.empty()) {
//            auto q = que.front();
//            que.pop();
//            
//            int x = q[0];
//            int y = q[1];
//            int dir = q[2];
//            
//            int step = vi[x][y][dir] + 1;
//            if (step > num) continue;
//            
//            int dx = x + dd[dir][0];
//            int dy = y + dd[dir][1];
//            if (dx < 0 || dx >= plate.size()) continue;
//            if (dy < 0 || dy >= plate[0].size()) continue;
//            
//            dir = (plate[dx][dy] == 'W') ? (dir + 1) % 4 : dir;
//            dir = (plate[dx][dy] == 'E') ? (dir + 3) % 4 : dir;
//            if (vi[dx][dy][dir] <= step) continue;
//            
//            vi[dx][dy][dir] = step;
//            que.push({dx, dy, dir});
//        }
//        
//        vector<vector<int>> ans;
//        for (int x = 1; x < plate.size() - 1; x++) {
//            Check(num, plate, vi, x, 0, 2, ans);
//            Check(num, plate, vi, x, plate[0].size() - 1, 0, ans);
//        }
//        for (int y = 1; y < plate[0].size() - 1; y++) {
//            Check(num, plate, vi, 0, y, 3, ans);
//            Check(num, plate, vi, plate.size() - 1, y, 1, ans);
//        }
//        return ans;
//    }
//
//    void Check(int num, vector<string>& plate, vector<vector<vector<int>>>& vi, int x, int y, int dir, vector<vector<int>>& ans) {
//        if (vi[x][y][dir] <= num && plate[x][y] == '.') {
//            ans.push_back({ x, y });
//        }
//    }
//    
//private:
//    vector<vector<int>> dd = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // → ↓ ← ↑
//};

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(int num, vector<string>& plate)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

    unique_ptr<Solution> sln(new Solution());
	return sln->ballGame(num, plate);
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
