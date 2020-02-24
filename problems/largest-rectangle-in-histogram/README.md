# `（困难）` [84.largest-rectangle-in-histogram 柱状图中最大的矩形](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/)

### 题目描述
<p>给定 <em>n</em> 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。</p>

<p>求在该柱状图中，能够勾勒出来的矩形的最大面积。</p>

<p>&nbsp;</p>

<p><img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/histogram.png"></p>

<p><small>以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为&nbsp;<code>[2,1,5,6,2,3]</code>。</small></p>

<p>&nbsp;</p>

<p><img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/histogram_area.png"></p>

<p><small>图中阴影部分为所能勾勒出的最大矩形面积，其面积为&nbsp;<code>10</code>&nbsp;个单位。</small></p>

<p>&nbsp;</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> [2,1,5,6,2,3]
<strong>输出:</strong> 10</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/84-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
	int largestRectangleArea(vector<int>& heights)
	{
		int ans = 0;
		vector<int> st;
		heights.insert(heights.begin(), 0);
		heights.push_back(0);
		for (int i = 0; i < heights.size(); i++)
		{
			while (!st.empty() && heights[st.back()] > heights[i])
			{
				int cur = st.back();
				st.pop_back();
				int left = st.back() + 1;
				int right = i - 1;
				ans = max(ans, (right - left + 1) * heights[cur]);
			}
			st.push_back(i);
		}
		return ans;
	}
};
```


### 其它
``` C++
class Solution {
public:
	vector<int> getBoundary(vector<int>& heights, bool left)
	{
		vector<int> ans(heights.size(), 0);
		vector<int> st;
		for (int ii = 0; ii < heights.size(); ii++)
		{
			int i = left ? heights.size() - 1 - ii : ii;
			while (!st.empty() && heights[st.back()] > heights[i])
			{
				ans[st.back()] = left ? i + 1 : i - 1;
				st.pop_back();
			}
			st.push_back(i);
		}
		return ans;
	}

	int largestRectangleArea(vector<int>& heights)
	{
		heights.push_back(0);
		vector<int> left = getBoundary(heights, true);
		vector<int> right = getBoundary(heights, false);

		int ans = 0;
		for (int i = 0; i < heights.size(); i++)
		{
			ans = max(ans, (right[i] - left[i] + 1) * heights[i]);
		}
		return ans;
	}
};
```


