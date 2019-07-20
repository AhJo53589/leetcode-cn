# `（简单）`  [198.house-robber 打家劫舍](https://leetcode-cn.com/problems/house-robber/)

### 题目描述
<p>你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，<strong>如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警</strong>。</p>

<p>给定一个代表每个房屋存放金额的非负整数数组，计算你<strong>在不触动警报装置的情况下，</strong>能够偷窃到的最高金额。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> [1,2,3,1]
<strong>输出:</strong> 4
<strong>解释:</strong> 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
&nbsp;    偷窃到的最高金额 = 1 + 3 = 4 。</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> [2,7,9,3,1]
<strong>输出:</strong> 12
<strong>解释:</strong> 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
&nbsp;    偷窃到的最高金额 = 2 + 9 + 1 = 12 。
</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/house-robber/solution/da-jia-jie-she-by-ikaruga/)

### 答题
``` C++
int rob(vector<int>& nums)
{
	int sumOdd = 0;
	int sumEven = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (i % 2 == 0)
		{
			sumOdd = max(sumOdd, sumEven);
			sumEven += nums[i];
		}
		else
		{
			sumEven = max(sumOdd, sumEven);
			sumOdd += nums[i];
		}
	}
	return max(sumOdd, sumEven);
}
```

### 其它
这道题上周五下班前没有做完，  
周日晚上想想这周结束之前还是应该把它完成。  

做完之后提交可能有bug，显示我战胜了100%的用户。  
很开心！  
算法也是纯自己研究的，  
就第一次写了个题解（已被选为精选题解）。  

学习了别人的动态规划方法。  
就感觉和我的方法很微妙的不同。  
``` C++
int rob(vector<int>& nums) 
{
	// 动态规划
	if (nums.size() == 0) return 0;
	if (nums.size() == 1)
		return nums[0];
	if (nums.size() == 2)
		return max(nums[0], nums[1]);
	nums[2] = nums[0] + nums[2];
	if (nums.size() == 3)
		return max(nums[1], nums[2]);
	for (int i = 3; i < nums.size(); i++)
	{
		nums[i] = max(nums[i - 2] + nums[i], nums[i] + nums[i - 3]);
	}
	return max(nums[nums.size() - 1], nums[nums.size() - 2]);
}
```

