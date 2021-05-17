
//////////////////////////////////////////////////////////////////////////
class Solution {
private:
    static constexpr int mod = 1000000007;

    using LL = long long;

public:
    int sumOfFlooredPairs(vector<int>& nums) {
        // 元素最大值
        int upper = *max_element(nums.begin(), nums.end());
        vector<int> cnt(upper + 1);
        for (int num : nums) {
            ++cnt[num];
        }
        // 预处理前缀和
        vector<int> pre(upper + 1);
        for (int i = 1; i <= upper; ++i) {
            pre[i] = pre[i - 1] + cnt[i];
        }

        LL ans = 0;
        for (int y = 1; y <= upper; ++y) {
            // 一个小优化，如果数组中没有 y 可以跳过
            if (cnt[y]) {
                for (int d = 1; d * y <= upper; ++d) {
                    ans += (LL)cnt[y] * d * (pre[min((d + 1) * y - 1, upper)] - pre[d * y - 1]);
                }
            }
        }
        return ans % mod;
    }
};


//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.sumOfFlooredPairs(nums);
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
