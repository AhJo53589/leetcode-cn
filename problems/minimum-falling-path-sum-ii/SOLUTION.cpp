


//////////////////////////////////////////////////////////////////////////
int minFallingPathSum(vector<vector<int>>& arr) 
{
	for (size_t i = 0; i < arr.size() - 1; i++)
	{
		size_t min1 = arr[i][0] < arr[i][1] ? 0 : 1;
		size_t min2 = arr[i][0] < arr[i][1] ? 1 : 0;
		for (size_t j = 2; j < arr[0].size(); j++)
		{
			if (arr[i][min1] > arr[i][j])
			{
				min2 = min1;
				min1 = j;
			}
			else if (arr[i][min2] > arr[i][j])
			{
				min2 = j;
			}
		}
		for (size_t j = 0; j < arr[0].size(); j++)
		{
			if (j == min1)
			{
				arr[i + 1][j] += arr[i][min2];
			}
			else
			{
				arr[i + 1][j] += arr[i][min1];
			}
		}
	}

	int ans = INT_MAX;
	for (size_t j = 0; j < arr[0].size(); j++)
	{
		ans = min(ans, arr[arr.size() - 1][j]);
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& arr)
{
	return minFallingPathSum(arr);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

