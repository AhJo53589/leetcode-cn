
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<long long, int> dic;
        for (int i = 0; i < stones.size(); i++) {
            dic[stones[i]] = i;
        }

        vector<unordered_set<long long>> dp(stones.size());
        dp[0].insert(1);
        for (int i = 0; i + 1 < stones.size(); i++) {
            if (dp[i].empty()) continue;
            for (auto step : dp[i]) {
                long long target = stones[i] + step;
                if (dic.find(target) == dic.end()) continue;
                if (dic[target] + 1 == stones.size()) return true;
                for (long long x = max(1LL, step - 1); x < step + 2; x++) {
                    dp[dic[target]].insert(x);
                }
            }
        }
        return false;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& stones)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.canCross(stones);
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
