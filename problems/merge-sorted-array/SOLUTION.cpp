


//////////////////////////////////////////////////////////////////////////
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
	int k = m + n;

	while (k > 0)
	{
		k -= 1;
		if (m > 0 && n > 0)
		{
			if (nums1[m - 1] < nums2[n - 1])
			{
				nums1[k] = nums2[n - 1];
				n -= 1;
			}
			else
			{
				nums1[k] = nums1[m - 1];
				m -= 1;
			}
		}
		else if (m == 0 && n != 0)
		{
			nums1[k] = nums2[n - 1];
			n -= 1;
		}
		else if (m != 0 && n == 0)
		{
			break;
			//nums1[k] = nums1[m - 1];
			//m -= 1;
		}
	}
}

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	merge(nums1,m,nums2,n);
	return nums1;
}

//#define USE_SOLUTION_CUSTOM
//void _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

