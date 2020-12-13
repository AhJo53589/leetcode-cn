
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        return dfs(stones, 0, stones.size() - 1, sum, 0);
    }

    int dfs(vector<int>& stones, int left, int right, int sum, int idx) {
        if (mp.find({ left, right, idx }) != mp.end()) {
            return mp[{ left, right, idx }];
        }

        if (left == right) return 0;
        int sc_l = dfs(stones, left + 1, right, sum - stones[left], (idx + 1) % 2);
        int sc_r = dfs(stones, left, right - 1, sum - stones[right], (idx + 1) % 2);

        int ret;
        if (idx == 0) {
            ret = max(sum - stones[left] + sc_l, sum - stones[right] + sc_r);
        }
        else {
            ret = min(sc_l - (sum - stones[left]), sc_r - (sum - stones[right]));
        }
        mp[{left, right, idx}] = ret;
        return ret;
    }

private:
    map<vector<int>, int> mp;
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& stones)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};
    printVectorT(stones);

    Solution sln;
    return sln.stoneGameVII(stones);
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
