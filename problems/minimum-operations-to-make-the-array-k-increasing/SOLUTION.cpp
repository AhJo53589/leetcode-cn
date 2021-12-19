
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        vector<vector<int>> vv(k, vector<int>());
        for (int i = 0; i < arr.size(); i++) {
            vv[i % k].push_back(arr[i]);
        }

        int ans = 0;
        for (auto& v : vv) {
            ans += (int)v.size() - lengthOfLIS(v);
        }
        return ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        int len = 1, n = (int)nums.size();
        if (n == 0) return 0;

        vector<int> d(n + 1, 0);
        d[len] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] >= d[len]) {
                d[++len] = nums[i];
            }
            else {
                int l = 1, r = len, pos = 0;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (d[mid] <= nums[i]) {
                        pos = mid;
                        l = mid + 1;
                    }
                    else {
                        r = mid - 1;
                    }
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& arr, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.kIncreasing(arr, k);
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
