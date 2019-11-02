


//////////////////////////////////////////////////////////////////////////
vector<int> transformArray(vector<int>& arr) 
{
	vector<int> arr2(arr.size());
	bool bChange = true;
	while (bChange)
	{
		bChange = false;
		arr2[0] = arr[0];
		arr2[arr.size() - 1] = arr[arr.size() - 1];
		for (size_t i = 1; i < arr.size() - 1; i++)
		{
			arr2[i] = arr[i];
			if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])
			{
				arr2[i]++;
				bChange = true;
			}
			else if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
			{
				arr2[i]--;
				bChange = true;
			}
		}
		swap(arr, arr2);
	}
	return arr;
}

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& arr)
{
	return transformArray(arr);
}

//#define USE_SOLUTION_CUSTOM
//vector<int> _solution_custom(TestCases &tc)
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
	return "../../problems/array-transformation/tests.txt";
}

