
//////////////////////////////////////////////////////////////////////////
//int findBestValue(vector<int>& arr, int target)
//{
//	int N = arr.size();
//	sort(arr.begin(), arr.end());
//
//	int k = target / N;
//	if (arr[0] > k)
//	{
//		return (abs(target - k * N) <= abs(target - (k + 1) * N)) ? k : k + 1;
//	}
//
//	int sum = accumulate(arr.begin(), arr.end(), 0);
//	if (sum <= target) return arr.back();
//
//	sum = 0;
//	for (size_t i = 0; i < arr.size(); i++)
//	{
//		if (arr[i] <= k)
//		{
//			sum += arr[i];
//			continue;
//		}
//		vector<int> arr2(arr.begin() + i, arr.end());
//		return findBestValue(arr2, target - sum);
//	}
//	return 0;
//}

//////////////////////////////////////////////////////////////////////////
int fun(vector<int>& arr, int target)
{
	int N = arr.size();
	int k = target / N;
	int sum = 0;

	size_t i = 0;
	for (; i < arr.size(); i++)
	{
		if (arr[i] > k) break;
		sum += arr[i];
	}

	if (i == 0)
	{
		return (abs(target - k * N) <= abs(target - (k + 1) * N)) ? k : k + 1;
	}
	else
	{
		vector<int> arr2(arr.begin() + i, arr.end());
		return fun(arr2, target - sum);
	}
}

int findBestValue(vector<int>& arr, int target)
{
	int sum = accumulate(arr.begin(), arr.end(), 0);
	if (sum <= target) return arr.back();

	sort(arr.begin(), arr.end());
	return fun(arr, target);
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

