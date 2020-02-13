//////////////////////////////////////////////////////////////////////////
//int missingNumber(vector<int>& arr) 
//{
//	// 数组求和
//	int sum = accumulate(arr.begin(), arr.end(), 0);
//	// 公式求和 - 数组求和
//	return (arr.size() + 1) * (arr.front() + arr.back()) / 2 - sum;
//}


//////////////////////////////////////////////////////////////////////////
int missingNumber(vector<int>& arr)
{
	if (arr.back() < arr.front())
	{
		reverse(arr.begin(), arr.end());
	}
	int k = arr[1] - arr[0];
	for (int i = 0; i < arr.size() - 1; i++)
	{
		if (arr[i + 1] - arr[i] == k) continue;
		if (arr[i + 1] - arr[i] > k) return arr[i] + k;
		break;
	}
	return arr[0] + k / 2;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& arr)
{
	return missingNumber(arr);
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


