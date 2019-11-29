//bool dfs(vector<int>& nums, vector<bool> visted, vector<bool> group, int gsum, size_t pos, int k, int sum)
//{
//	if (k == 0) return true;
//	if (pos >= nums.size()) return false;
//	if (visted[pos])
//	{
//		return dfs(nums, visted, group, gsum, pos - 1, k, sum);
//	}
//
//	for (size_t i = pos; i < nums.size(); i--)
//	{
//		if (visted[i]) continue;
//		if (group[i]) continue;
//		if (gsum + nums[i] > sum) continue;
//		if (gsum + nums[i] == sum)
//		{
//			group[i] = true;
//			for (auto g = 0; g < group.size(); g++)
//			{
//				visted[g] = (group[g]) ? true : visted[g];
//			}
//			k--;
//			if (dfs(nums, visted, vector<bool>(nums.size(), false), 0, pos - 1, k, sum))
//			{
//				return true;
//			}
//			for (auto g = 0; g < group.size(); g++)
//			{
//				visted[g] = (group[g]) ? false : visted[g];
//			}
//			k++;
//		}
//		else
//		{
//			group[i] = true;
//			gsum += nums[i];
//			if (dfs(nums, visted, group, gsum, pos, k, sum))
//			{
//				return true;
//			}
//			group[i] = false;
//			gsum -= nums[i];
//		}
//	}
//	return false;
//}
//
//bool canPartitionKSubsets(vector<int>& nums, int k)
//{
//	sort(nums.begin(), nums.end());
//	int sum = accumulate(nums.begin(), nums.end(), 0);
//	if ((sum % k) != 0) return false;
//	int avg = sum / k;
//	if (nums.back() > avg) return false;
//
//	return dfs(nums, vector<bool>(nums.size(), false), vector<bool>(nums.size(), false), 0, nums.size() - 1, k, avg);
//}


//////////////////////////////////////////////////////////////////////////
bool dfs(vector<int>& nums, vector<int>& visited, int sum, int k, int target)
{
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (visited[i] == 1) continue;
		if (sum + nums[i] > target) continue;
		if (sum + nums[i] == target)
		{
			if (--k == 0) return true;
			visited[i] = 1;
			if (dfs(nums, visited, 0, k, target))
			{
				return true;
			}
			visited[i] = 0;
			k++;
		}
		else
		{
			visited[i] = 1;
			if (dfs(nums, visited, sum + nums[i], k, target))
			{
				return true;
			}
			visited[i] = 0;
		}
	}
	return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k)
{
	sort(nums.rbegin(), nums.rend());
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if (sum % k != 0) return false;
	int avg = sum / k;
	if (nums.front() > avg) return false;

	vector<int> visited(nums.size(), 0);
	return dfs(nums, visited, 0, k, avg);
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& nums, int k)
{
	return canPartitionKSubsets(nums,k);
}

//#define USE_SOLUTION_CUSTOM
//bool _solution_custom(TestCases &tc)
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
	return "../../problems/_test_0/tests.txt";
}

