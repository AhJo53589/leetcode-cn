
//////////////////////////////////////////////////////////////////////////
//int trap(vector<int>& height, int &first, int last)
//{
//	int ans = 0;
//	int cut = 0;
//
//	for (int i = 0; i < last; i++)
//	{
//		if (first == -1)
//		{
//			first = (height[i] != 0) ? i : first;
//			continue;
//		}
//
//		if (height[i] < height[first])
//		{
//			cut += height[i];
//		}
//		else
//		{
//			ans += (i - first - 1) * min(height[first], height[i]) - cut;
//			first = i;
//			cut = 0;
//		}
//	}
//
//	return ans;
//}
//
//int trap(vector<int>& height)
//{
//	if (height.empty()) return 0;
//
//	int ans = 0;
//	int first = -1;
//	int last = height.size();
//	ans = trap(height, first, last);
//	if (first == -1) return ans;
//
//	reverse(height.begin(), height.end());
//	last = height.size() - first;
//	first = -1;
//	ans += trap(height, first, last);
//
//	return ans;
//}


//////////////////////////////////////////////////////////////////////////
int trap(vector<int>& height)
{
	if (height.empty()) return 0;

	int ans = 0;
	int left = -1;
	int cut = 0;
	for (int i = 0; i < height.size(); i++)
	{
		if (left == -1)
		{
			left = (height[i] != 0) ? i : left;
			continue;
		}

		if (height[i] < height[left])
		{
			cut += height[i];
		}
		else
		{
			ans += (i - left - 1) * min(height[left], height[i]) - cut;
			left = i;
			cut = 0;
		}
	}
	if (left == -1) return ans;

	cut = 0;
	int right = height.size();
	for (int i = height.size() - 1; i >= left; i--)
	{
		if (right == height.size())
		{
			right = (height[i] != 0) ? i : right;
			continue;
		}

		if (height[i] < height[right])
		{
			cut += height[i];
		}
		else
		{
			ans += (right - i - 1) * min(height[right], height[i]) - cut;
			right = i;
			cut = 0;
		}
	}
	return ans;
}


//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& height)
{
	return trap(height);
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
	return "../../problems/trapping-rain-water/tests.txt";
}

