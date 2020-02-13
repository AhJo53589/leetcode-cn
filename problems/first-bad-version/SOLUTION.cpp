
bool isBadVersion(int version)
{
	return (version >= 4);
}


//////////////////////////////////////////////////////////////////////////
int firstBadVersion(int n)
{
	int low = 1;
	int high = n;

	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (isBadVersion(mid))
		{
			high = mid;
		}
		else
		{
			low = mid + 1;
		}
	}
	return low;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n)
{
	return firstBadVersion(n);
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

