
//vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//	int left = 0, right = arr.size() - k;
//	while (left < right) {
//		int mid = left + (right - left) / 2;
//		if (x - arr[mid] > arr[mid + k] - x) left = mid + 1;
//		else right = mid;
//	}
//	return vector<int>(arr.begin() + left, arr.begin() + left + k);
//}
//
//
//vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//	int size = arr.size(), n = size - k;
//	int left = 0, right = size - 1;
//	while (n) {
//
//		if (x - arr[left] <= arr[right] - x)
//			right--;
//		else
//			left++;
//		n--;
//	}
//	vector<int> a;
//	//        for(int i=left; i<=right; ++i)
//	//            a.push_back(arr[i]);
//	a.assign(arr.begin() + left, arr.begin() + right + 1);
//	return a;
//}


//////////////////////////////////////////////////////////////////////////
vector<int> findClosestElements(vector<int>& arr, int k, int x)
{
	int low = 0;
	int high = arr.size();
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (arr[mid] < x) low = mid + 1;
		else high = mid;
	}
	int mid = low;
	while (high - low < k)
	{
		if (k > arr.size()) return {};
		if (low == 0)
		{
			high = high + 1;
			continue;
		}
		else if (high == arr.size())
		{
			low = low - 1;
			continue;
		}

		if (x - arr[low - 1] <= arr[high] - x) low = low - 1;
		else high = high + 1;
	}
	vector<int> res;
	res.assign(&arr[low], &arr[high]);
	return res;
}


//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& arr, int k, int x)
{
	return findClosestElements(arr,k,x);
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

