

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int len = nums.size();
    if (len < 3) return ans;
    for (int i = 0; i < len; i++)
    {
        if (nums[i] > 0) break; // 如果当前数字大于0，则三数之和一定大于0，所以结束循环
        if (i > 0 && nums[i] == nums[i - 1]) continue; // 去重
        int L = i + 1;
        int R = len - 1;
        while (L < R)
        {
            int sum = nums[i] + nums[L] + nums[R];
            if (sum == 0)
            {
                ans.push_back({ nums[i], nums[L], nums[R] });
                while (L < R && nums[L] == nums[L + 1]) L++; // 去重
                while (L < R && nums[R] == nums[R - 1]) R--; // 去重
                L++;
                R--;
            }
            else if (sum < 0) L++;
            else if (sum > 0) R--;
        }
    }
    return ans;
}

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<int>& nums)
{
    return threeSum(nums);
}

//#define USE_SOLUTION_CUSTOM
//vector<vector<int>> _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}

