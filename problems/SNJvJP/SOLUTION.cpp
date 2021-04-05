
//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
    int orchestraLayout(int num, int xPos, int yPos) {
        long long ans = 0;
        long long i = xPos + 1;
        long long j = yPos + 1;
        long long m = min({ i, j, num - i + 1, num - j + 1 });
        if (i <= j) {
            ans = m * (1LL * 4 * (num - 1) - 4 * m) + 10 * m - 1LL * 4 * num - 3 + i + j;
        }
        else {
            ans = m * (1LL * 4 * num - 4 * m) + 2 * m + 1 - i - j;
        }
        ans %= 9;
        return ans == 0 ? 9 : ans;
    }
};

class Solution {
public:
    int orchestraLayout(int num, int xPos, int yPos) {
        int up = xPos;
        int down = num - xPos - 1;
        int left = yPos;
        int right = num - yPos - 1;

        int turn = min({ up, down, left, right });

        long long a = 1LL * num * 4 - 4;
        long long b = 1LL * (num - (turn - 1) * 2) * 4 - 4;
        long long ans = 0;
        if (turn != 0) {
            ans = (turn == 1) ? a : (a + b) * turn / 2;
        }
        num -= turn * 2;
        xPos -= turn;
        yPos -= turn;

        vector<int> sz = { num, num - 1 };
        vector<vector<int>> dd = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

        for (int d = 0, x = 0, y = -1; ; d = (d + 1) % dd.size()) {
            if (x != xPos && y != yPos) {
                x += dd[d][0] * sz[d % 2];
                y += dd[d][1] * sz[d % 2];
                ans += sz[d % 2];
            }
            else {
                ans += max(abs(x - xPos), abs(y - yPos));
                break;
            }
            sz[d % 2]--;
        }

        return ((ans - 1) % 9) + 1;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int num, int xPos, int yPos)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << num << ", " << xPos << ", " << yPos << endl;

    Solution sln;
    return sln.orchestraLayout(num, xPos, yPos);
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
