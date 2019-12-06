


//////////////////////////////////////////////////////////////////////////
int removeDuplicates(vector<int>& nums)
{
	int iLen = nums.size();
	if (nums.size() < 2) return iLen;

	int iIndex = 1;
	for (int i = 2; i < iLen; i++)
	{
		if (nums[i] != nums[iIndex - 1])
		{
			nums[++iIndex] = nums[i];
		}
	}
	return iIndex + 1;
}

//////////////////////////////////////////////////////////////////////////
//int _solution_run(vector<int>& nums)
//{
//	return removeDuplicates(nums);
//}

#define USE_SOLUTION_CUSTOM
vector<int> _solution_custom(TestCases &tc)
{
	vector<int> nums = tc.get<vector<int>>();
	vector<int> ans;

	// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
	int len = removeDuplicates(nums);

	// 在函数里修改输入数组对于调用者是可见的。
	// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
	for (int i = 0; i < len; i++)
	{
		ans.push_back(nums[i]);
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/remove-duplicates-from-sorted-array-ii/tests.txt";
}

