


//////////////////////////////////////////////////////////////////////////
vector<int> twoSum(vector<int>& numbers, int target)
{
	int low = 0;
	int high = numbers.size() - 1;
	while (low < high)
	{
		if (numbers[low] + numbers[high] > target) high--;
		else if (numbers[low] + numbers[high] < target) low++;
		else return { low + 1, high + 1 };
	}
	return { -1, -1 };
}

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& numbers, int target)
{
	return twoSum(numbers,target);
}

//#define USE_SOLUTION_CUSTOM
//vector<int> _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

