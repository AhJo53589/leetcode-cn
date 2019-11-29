
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
	return "../../problems/partition-to-k-equal-sum-subsets/tests.txt";
}

