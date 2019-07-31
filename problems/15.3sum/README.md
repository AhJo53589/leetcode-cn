# `（中等）`  [15.3sum 三数之和](https://leetcode-cn.com/problems/3sum/)

### 题目描述
<p>给定一个包含 <em>n</em> 个整数的数组&nbsp;<code>nums</code>，判断&nbsp;<code>nums</code>&nbsp;中是否存在三个元素 <em>a，b，c ，</em>使得&nbsp;<em>a + b + c = </em>0 ？找出所有满足条件且不重复的三元组。</p>

<p><strong>注意：</strong>答案中不可以包含重复的三元组。</p>

<pre>例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
</pre>


---
### 思路
```
```

### 答题
``` C++
vector<vector<int>> threeSum(vector<int>& nums)
{
	vector<vector<int>> ans;
	sort(nums.begin(), nums.end());
	int len = nums.size();
	if (len < 3) return ans;
	for (int i = 0; i < len; i++) 
	{
		if (nums[i] > 0) break; // 如果当前数字大于0，则三数之和一定大于0，所以结束循环
		if (i > 0 && nums[i] == nums[i - 1]) continue; // 去重
		int L = i + 1;
		int R = len - 1;
		while (L < R) 
		{
			int sum = nums[i] + nums[L] + nums[R];
			if (sum == 0) 
			{
				ans.push_back({ nums[i], nums[L], nums[R] });
				while (L < R && nums[L] == nums[L + 1]) L++; // 去重
				while (L < R && nums[R] == nums[R - 1]) R--; // 去重
				L++;
				R--;
			}
			else if (sum < 0) L++;
			else if (sum > 0) R--;
		}
	}
	return ans;
}
```

### 其它
我的算法超时了。
``` C++
vector<vector<int>> threeSum(vector<int>& nums)	// 超时
{
	vector<vector<int>> ret;
	unordered_multimap<int, pair<int, int>> map_2;
	int low = -1;
	int high = -1;
	int mid = 0;
	sort(nums.begin(), nums.end());

	if (nums.size() < 3) return {};
	if (nums[0] > 0) return {};
	if (nums[nums.size() - 1] < 0) return {};
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] < 0) low = i;
		if (nums[i] == 0) mid++;
		if (nums[i] > 0)
		{
			high = i;
			break;
		}
	}
	if ((low == -1 || high == -1) && mid >= 3) return { {0, 0, 0} };
	if ((low == -1 || high == -1) && mid < 3) return {};

	for (int i = 0; i <= low; i++)
	{
		if (i != 0 && nums[i] == nums[i - 1]) continue;
		for (int j = nums.size() - 1; j >= high; j--)
		{
			if (j != nums.size() - 1 && nums[j] == nums[j + 1]) continue;
			map_2.insert({ nums[i] + nums[j], {i, j} });
		}
	}
	for (int i = 0; i < nums.size(); i++)
	{
		if (i < low && nums[i] == nums[i + 1]) continue;
		if (nums[i] == 0 && nums[i + 1] == 0) continue;
		if (i > high && nums[i] == nums[i - 1]) continue;
		auto pr = map_2.equal_range(-nums[i]);
		while (pr.first != pr.second)
		{
			if (pr.first->second.first < i && i < pr.first->second.second)
			{
				ret.push_back({ nums[pr.first->second.first], nums[i], nums[pr.first->second.second] });
			}
			++pr.first;
		}
	}
	if (mid >= 3) ret.push_back({ 0, 0, 0 });
	return ret;
}
```

