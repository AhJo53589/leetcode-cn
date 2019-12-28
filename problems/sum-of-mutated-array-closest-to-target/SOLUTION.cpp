


//////////////////////////////////////////////////////////////////////////
int findBestValue(vector<int>& arr, int target)
{
	int N = arr.size();
	sort(arr.begin(), arr.end());

	int k = target / N;
	if (arr[0] > k)
	{
		if (abs(target - k * N) < abs(target - (k + 1) * N))
		{
			return k;
		}
		return k + 1;
	}

	int sum = 0;
	for (auto n : arr)
	{
		sum += n;
	}
	if (sum <= target)
	{
		return arr.back();
	}

	sum = 0;
	for (size_t i = 0; i < arr.size(); i++)
	{
		if (arr[i] <= k)
		{
			sum += arr[i];
			continue;
		}
		vector<int> arr2(arr.begin() + i, arr.end());
		return findBestValue(arr2, target - sum - 1);
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& arr, int target)
{
	return findBestValue(arr,target);
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
	return "../../problems/sum-of-mutated-array-closest-to-target/tests.txt";
}

