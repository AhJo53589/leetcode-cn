
//////////////////////////////////////////////////////////////////////////
int getSum(vector<int>& nums, int d)
{
    int ans = 0;
    for (auto n : nums)
    {
        ans += n / d + ((n % d) != 0);
    }
    return ans;
}

int smallestDivisor(vector<int>& nums, int threshold) 
{
    int left = 1;
    int right = 1;
    for (auto n : nums)
    {
        right = max(right, n);
    }

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (getSum(nums, mid) > threshold)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return left;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums, int threshold)
{
	return smallestDivisor(nums,threshold);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/find-the-smallest-divisor-given-a-threshold/tests.txt";
}

