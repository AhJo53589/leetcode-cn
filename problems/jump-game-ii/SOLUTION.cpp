
//////////////////////////////////////////////////////////////////////////
int jump(vector<int>& nums)
{
    int ans = 0;
    int end = 0;
    int maxPos = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        maxPos = max(nums[i] + i, maxPos);
        if (i == end)
        {
            end = maxPos;
            ans++;
        }
    }
    return ans;
}

//////////////////////////////////////////////////////////////////////////
//int jump(vector<int> &nums)
//{
//    int ans = 0;
//    int start = 0;
//    int end = 1;
//    while (end < nums.size())
//    {
//        int maxPos = 0;
//        for (int i = start; i < end; i++)
//        {
//            maxPos = max(maxPos, i + nums[i]);
//        }
//        start = end;
//        end = maxPos + 1;
//        ans++;
//    }
//    return ans;
//}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int> &nums)
{
    return jump(nums);
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

