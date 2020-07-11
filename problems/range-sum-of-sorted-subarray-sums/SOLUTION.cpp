
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int mod = 1e9 + 7;

        vector<int> v;
        for (int i = 0; i < n; ++i) {
            partial_sum(nums.begin() + i, nums.end(), back_inserter(v));
        }
        sort(v.begin(), v.end());

        int ans = 0;
        for (int i = left - 1; i < right; ++i) {
            ans += v[i];
            ans %= mod;
        }
        return ans;
    }
};

class Solution2 {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long> pnums(nums.size());
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += (long long)nums[i];
            pnums[i] = sum;
        }
        //partial_sum(nums.begin(), nums.end(), back_inserter(pnums));

        vector<long long> n_nums(nums.size() * (nums.size() + 1) / 2);
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                if (i == 0) {
                    n_nums[idx++] = pnums[j];
                }
                else {
                    n_nums[idx++] = pnums[j] - pnums[i - 1];
                }
            }
        }

        sort(n_nums.begin(), n_nums.end());

        int ans = 0;
        for (int i = left - 1; i <= right - 1; i++) {
            n_nums[i] %= (long long)mod;
            ans += static_cast<int>(n_nums[i]);
            ans %= mod;
        }

        return ans;
    }

private:
    const int mod = 1e9 + 7;
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums, int n, int left, int right)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(nums);

    Solution sln;
    return sln.rangeSum(nums, n, left, right);
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
