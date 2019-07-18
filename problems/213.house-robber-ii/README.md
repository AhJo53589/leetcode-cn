# `（中等）`  [213.house-robber-ii 打家劫舍 II](https://leetcode-cn.com/problems/house-robber-ii/)

### 题目描述
<p>你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都<strong>围成一圈，</strong>这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，<strong>如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警</strong>。</p>

<p>给定一个代表每个房屋存放金额的非负整数数组，计算你<strong>在不触动警报装置的情况下，</strong>能够偷窃到的最高金额。</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong> [2,3,2]
<strong>输出:</strong> 3
<strong>解释:</strong> 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> [1,2,3,1]
<strong>输出:</strong> 4
<strong>解释:</strong> 你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
&nbsp;    偷窃到的最高金额 = 1 + 3 = 4 。</pre>


---
### 思路
```
```

[题解] (https://leetcode-cn.com/problems/house-robber-ii/solution/da-jia-jie-she-ii-dai-ma-jian-ji-yi-dong-ii-by-ika/)

### 答题
``` C++
int rob(vector<int>& nums)
{
	if (nums.size() == 1) return nums[0];

	int sumOdd[2] = {0, 0};	// 0 == head, 1 == tail
	int sumEven[2] = { 0, 0 };
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (i == 0 && j == 1) continue;	// head only
			if (i == nums.size() - 1 && j == 0) continue;	// tail only
			if (i % 2 == 0)
			{
				sumOdd[j] = max(sumOdd[j], sumEven[j]);
				sumEven[j] += nums[i];
			}
			else
			{
				sumEven[j] = max(sumOdd[j], sumEven[j]);
				sumOdd[j] += nums[i];
			}
		}
	}

	for (int j = 0; j < 2; j++)
	{
		sumOdd[j] = max(sumOdd[j], sumEven[j]);
	}
	return max(sumOdd[0], sumOdd[1]);
}
```
