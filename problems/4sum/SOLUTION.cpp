
//////////////////////////////////////////////////////////////////////////
//vector<vector<int>> fourSum(vector<int>& nums, int target)
//{
//	vector<vector<int>> res;
//	int size = nums.size();
//	if (size < 4) return res;
//
//	sort(nums.begin(), nums.end());
//	for (int i = 0; i < size - 3; i++)
//	{
//		if (i > 0 && nums[i] == nums[i - 1]) continue;
//		if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
//		if (nums[i] + nums[size - 3] + nums[size - 2] + nums[size - 1] < target) continue;
//
//		for (int j = i + 1; j < size - 2; j++)
//		{
//			if (j > i + 1 && nums[j] == nums[j - 1]) continue;
//			if (nums[i] + nums[j] + nums[size - 2] + nums[size - 1] < target) continue;
//			if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
//
//			int k = j + 1;
//			int m = size - 1;
//			while (k < m)
//			{
//				int sum = nums[i] + nums[j] + nums[k] + nums[m];
//				if (sum < target) k++;
//				else if (sum > target) m--;
//				else
//				{
//					res.push_back(vector<int> {nums[i], nums[j], nums[k], nums[m]});
//					do { k++; } while (nums[k] == nums[k - 1] && k < m);
//					do { m--; } while (nums[m] == nums[m + 1] && k < m);
//				}
//			}
//		}
//	}
//	return res;
//}


//////////////////////////////////////////////////////////////////////////
vector<vector<int>> fourSum(vector<int>& nums, int target) {
	if (nums.size() < 4) return {};
	sort(nums.begin(), nums.end());
	vector<vector<int>> res;
	set<vector<int>> a;
	for (int i = 0; i < nums.size() - 3; i++)
	{
		if (nums[i] > target&&target > 0) break;
		for (int j = i + 1; j < nums.size() - 2; j++)
		{
			int l = j + 1;
			int r = nums.size() - 1;
			while (l < r)
			{
				if (nums[i] + nums[j] + nums[l] + nums[r] < target)
					l++;
				else if (nums[i] + nums[j] + nums[l] + nums[r] > target)
					r--;
				else
				{
					vector<int> temp{ nums[i],nums[j],nums[l],nums[r] };
					a.insert(temp);
					l++;
					r--;
				}
			}
		}
	}
	for (auto c : a)
	{
		res.push_back(c);
	}
	return res;
}


//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<int>& nums, int target)
{
	return fourSum(nums,target);
}

//#define USE_SOLUTION_CUSTOM
//vector<vector<int>> _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

