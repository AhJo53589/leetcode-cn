
//////////////////////////////////////////////////////////////////////////
//int lowerbound(vector<int>& row, int val)
//{
//	int low = 0;
//	int high = row.size();
//	while (low < high)
//	{
//		int mid = low + (high - low) / 2;
//		if (row[mid] <= val)
//		{
//			low = mid + 1;
//		}
//		else
//		{
//			high = mid;
//		}
//	}
//	return low;
//}
//
//int kthSmallest(vector<vector<int>>& matrix, int k)
//{
//	size_t m = matrix.size();
//	if (m == 0) return 0;
//
//	int low = matrix[0][0];
//	int high = matrix.back().back();
//
//	while (low < high)
//	{
//		int mid = low + (high - low) / 2;
//		cout << "low = " << low << ", high = " << high << endl;
//		cout << "mid = " << mid << endl;
//
//		int count = 0;
//		for (auto &row : matrix)
//		{
//			count += lowerbound(row, mid);
//			printVectorT(row);
//			cout << "count = " << count << endl;
//			if (count > k) break;
//		}
//		cout << endl;
//		if (count < k)
//		{
//			low = mid + 1;
//		}
//		else
//		{
//			high = mid;
//		}
//	}
//	return low;
//}


//////////////////////////////////////////////////////////////////////////
int lowerbound(vector<int>& row, int val)
{
	int low = 0;
	int high = row.size();
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (row[mid] <= val)
		{
			low = mid + 1;
		}
		else
		{
			high = mid;
		}
	}
	return low;
}



//////////////////////////////////////////////////////////////////////////
int kthSmallest(vector<vector<int>>& matrix, int k)
{
	size_t m = matrix.size();
	if (m == 0) return 0;

	int low = matrix[0][0];
	int high = matrix.back().back();

	while (low < high)
	{
		int mid = low + (high - low) / 2;
		int count = 0;
		for (auto &row : matrix)
		{
			count += lowerbound(row, mid);
			if (count > k) break;
		}
		if (count < k)
		{
			low = mid + 1;
		}
		else
		{
			high = mid;
		}
	}
	return low;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& matrix, int k)
{
	return kthSmallest(matrix,k);
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

