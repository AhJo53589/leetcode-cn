
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        const int mod = 1e9 + 7;
        int ans = 0;

        vector<int> pre(1, 0);
        partial_sum(nums.begin(), nums.end(), back_inserter(pre));

        for (int i = 1; i + 2 <= nums.size(); i++) {
            int left = lower_bound(pre, 2 * pre[i]);
            int right = upper_bound(pre, (pre.back() + pre[i]) / 2);
            left = max(left, i + 1);
            right = min(right, (int)nums.size());
            ans += max(0, right - left);
            ans %= mod;
        }

        return ans;
    }

    int lower_bound(vector<int>& pre, int target) {
        int low = 0;
        int high = pre.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (pre[mid] >= target) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }

    int upper_bound(vector<int>& pre, int target) {
        return lower_bound(pre, target + 1);
    }
};


//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
    int waysToSplit(vector<int>& nums) {
        const int mod = 1e9 + 7;
        int ans = 0;

        vector<int> pre(1, 0);
        partial_sum(nums.begin(), nums.end(), back_inserter(pre));

        for (int i = 1; i + 2 <= nums.size(); i++) {
            int left = lower_bound(pre.begin(), pre.end(), 2 * pre[i]) - pre.begin();
            int right = upper_bound(pre.begin(), pre.end(), (pre.back() + pre[i]) / 2) - pre.begin();
            left = max(left, i + 1);
            right = min(right, (int)nums.size());
            ans += max(0, right - left);
            ans %= mod;
        }

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    //printVectorT(nums);

    Solution2 sln;
    return sln.waysToSplit(nums);
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
