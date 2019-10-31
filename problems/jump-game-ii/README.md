# `（困难）` [45.jump-game-ii 跳跃游戏 II](https://leetcode-cn.com/problems/jump-game-ii/)

### 题目描述
<p>给定一个非负整数数组，你最初位于数组的第一个位置。</p>
<p>数组中的每个元素代表你在该位置可以跳跃的最大长度。</p>
<p>你的目标是使用最少的跳跃次数到达数组的最后一个位置。</p>
<p><strong>示例:</strong></p>
<pre><strong>输入:</strong> [2,3,1,1,4]
<strong>输出:</strong> 2
<strong>解释:</strong> 跳到最后一个位置的最小跳跃数是 <code>2</code>。
&nbsp;    从下标为 0 跳到下标为 1 的位置，跳&nbsp;<code>1</code>&nbsp;步，然后跳&nbsp;<code>3</code>&nbsp;步到达数组的最后一个位置。
</pre>

<p><strong>说明:</strong></p>
<p>假设你总是可以到达数组的最后一个位置。</p>

---
### 思路
```

```

[发布的题解](https://leetcode-cn.com/problems/jump-game-ii/solution/45-by-ikaruga/)

### 答题
``` C++
int jump(vector<int> &nums)
{
	int ans = 0;
	int begin = 0;
	int end = 1;
	while (end < nums.size())
	{
		int temp = 0;
		for (int i = begin; i < end; i++)
		{
			temp = max(temp, i + nums[i]);
		}
		begin = end;
		end = temp + 1;
		ans++;
	}
	return ans;
}
```

### 其它
``` C++
int jump(vector<int> &nums)
{
	int ans = 0;
	int end = 0;
	int maxPos = 0;
	for (int i = 0; i < nums.size() - 1; i++)
	{
		maxPos = max(nums[i] + i, maxPos);
		if (i == end)
		{
			end = maxPos;
			ans++;
		}
	}
	return ans;
}
```

