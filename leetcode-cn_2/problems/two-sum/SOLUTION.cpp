

vector<int> twoSum(vector<int> &nums, int target)
{
	map<int, int> sum;
	vector<int> rst;
	for (int i = 0; i < nums.size(); i++)
	{
		if (sum.find(target - nums[i]) != sum.end())
		{
			rst.push_back(sum[target - nums[i]]);
			rst.push_back(i);
			break;
		}
		else
		{
			sum[nums[i]] = i;
		}
	}
	return rst;
}

//vector<int> twoSum(vector<int> &nums, int target)	// 4ms
//{
//	vector<int> v;
//	unordered_map<int, int> hash;
//	for (int i = nums.size() - 1; i >= 0; hash[nums[i]] = i, i--)
//	{
//		if (hash.find(target - nums[i]) == hash.end())
//			continue;
//		v.push_back(i);
//		v.push_back(hash[target - nums[i]]);
//		return v;
//	}
//	return v;
//}

vector<int> solution(vector<int> nums, int target)
{
	return  twoSum(nums, target);
}


