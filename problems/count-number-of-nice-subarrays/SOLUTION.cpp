//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> arr;
        arr.push_back(0);
        for (auto x : nums) arr.push_back(arr.back() + (x & 1));

        unordered_map<int, int> h;
        int ans = 0;

        for (auto x : arr) {
            ans += h[x - k];
            h[x] ++;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k)
    {
        vector<int> odd;
        odd.push_back(-1);

        int ans = 0;
        int i = 1;
        for (int j = 0; j <= nums.size(); j++)
        {
            if (j == nums.size() || (nums[j] & 1))
            {
                odd.push_back(j);
            }

            if (odd.size() - i > k)
            {
                int left = odd[i] - odd[i - 1];
                int right = j - odd[odd.size() - 2];
                ans += left * right;
                i++;
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums, int k)
{
    Solution sln;
    return sln.numberOfSubarrays(nums,k);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}

