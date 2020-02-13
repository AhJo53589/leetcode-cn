
//////////////////////////////////////////////////////////////////////////
//bool increasingTriplet(vector<int>& nums) 
//{
//	int a = INT_MAX;
//	int b = INT_MAX;
//
//	for (auto e : nums) 
//	{
//		if (e <= a) a = e;
//		else if (e <= b) b = e;
//		else return true;
//	}
//	return false;
//}

////////////////////////////////////////////////////////////////////////////
//// 调试版
//bool increasingTriplet_test(vector<int>& nums)
//{
//	int l = 0;
//	int l2 = 0;
//	int m = 0;
//	for (int i = 1; i < nums.size(); i++)
//	{
//		if (m == l)
//		{
//			if (nums[l] < nums[i])
//			{
//				m = i;
//				cout << "i = " << i << " | ";
//				cout << "m = " << nums[i] << endl;
//			}
//			else
//			{
//				l = i;
//				l2 = i;
//				m = i;
//				cout << "i = " << i << " | ";
//				cout << "l = " << nums[i] << ", ";
//				cout << "l2 = " << nums[i] << ", ";
//				cout << "m = " << nums[i] << endl;
//			}
//		}
//		else
//		{
//			if (nums[m] < nums[i])
//			{
//				cout << "i = " << i << " | ";
//				cout << "Find = " << nums[l] << "," << nums[m] << "," << nums[i] << endl;
//				return true;
//			}
//			if (nums[i] < nums[l2])
//			{
//				l2 = i;
//				cout << "i = " << i << " | ";
//				cout << "l2 = " << nums[i] << endl;
//			}
//			else if (nums[l2] < nums[i] && nums[i] < nums[m])
//			{
//				l = l2;
//				m = i;
//				cout << "i = " << i << " | (l = l2) ";
//				cout << "l = " << nums[l2] << ", ";
//				cout << "m = " << nums[i] << endl;
//			}
//		}
//	}
//	return false;
//}

//////////////////////////////////////////////////////////////////////////
bool increasingTriplet(vector<int>& nums)
{
	if (nums.size() < 3) return false;
	int l = 0;
	int l2 = 0;
	int m = 0;
	for (int i = 1; i < nums.size(); i++)
	{
		if (m == l)
		{
			if (nums[l] < nums[i]) m = i;
			else
			{
				l = i;
				l2 = i;
				m = i;
			}
		}
		else
		{
			if (nums[m] < nums[i]) return true;
			if (nums[i] < nums[l2]) l2 = i;
			else if (nums[l2] < nums[i] && nums[i] < nums[m])
			{
				l = l2;
				m = i;
			}
		}
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& nums)
{
	return increasingTriplet(nums);
}

//#define USE_SOLUTION_CUSTOM
//bool _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

