
//////////////////////////////////////////////////////////////////////////
//int maxArea(vector<int>& height) {
//	int start = 0, end = height.size() - 1, op = 0;
//	while (start < end)
//	{
//		op = max(op, min(height[start], height[end])*(end - start));
//		height[start] < height[end] ? ++start : --end;
//	}
//	return op;
//}

//////////////////////////////////////////////////////////////////////////
int maxArea(vector<int>& nums)
{
	auto getArea = [nums](int low, int high) { return min(nums[low], nums[high]) * abs(low - high); };
	vector<int> left;
	vector<int> right;
	int iMax = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] > iMax) left.push_back(i);
		iMax = max(iMax, nums[i]);
	}
	iMax = 0;
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		if (nums[i] > iMax) right.push_back(i);
		iMax = max(iMax, nums[i]);
	}
	iMax = 0;
	int i = 0;
	int j = 0;
	while (i < left.size() && j < right.size() && left[i] < right[j])
	{
		iMax = max(iMax, getArea(left[i], right[j]));
		nums[left[i]] < nums[right[j]] ? i++ : j++;
	}
	return iMax;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
	return maxArea(nums);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {
};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/container-with-most-water/tests.txt";
}

