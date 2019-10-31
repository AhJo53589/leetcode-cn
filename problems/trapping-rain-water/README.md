# `（困难）` [42.trapping-rain-water 接雨水](https://leetcode-cn.com/problems/trapping-rain-water/)

### 题目描述
<p>给定&nbsp;<em>n</em> 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。</p>

<p><img style="height: 161px; width: 412px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/rainwatertrap.png"></p>

<p><small>上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。&nbsp;<strong>感谢 Marcos</strong> 贡献此图。</small></p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> [0,1,0,2,1,0,1,3,2,1,2,1]
<strong>输出:</strong> 6</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/trapping-rain-water/solution/42-by-ikaruga/)

### 答题
``` C++
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
```
