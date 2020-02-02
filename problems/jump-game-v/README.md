# `（困难）` [5331.jump-game-v 跳跃游戏 V](https://leetcode-cn.com/problems/jump-game-v/)

[contest](https://leetcode-cn.com/contest/weekly-contest-174/problems/jump-game-v/)

### 题目描述
<p>给你一个整数数组&nbsp;<code>arr</code> 和一个整数&nbsp;<code>d</code> 。每一步你可以从下标&nbsp;<code>i</code>&nbsp;跳到：</p>
<ul>
	<li><code>i + x</code>&nbsp;，其中&nbsp;<code>i + x &lt; arr.length</code>&nbsp;且&nbsp;<code>0 &lt; x &lt;= d</code>&nbsp;。</li>
	<li><code>i - x</code>&nbsp;，其中&nbsp;<code>i - x &gt;= 0</code>&nbsp;且&nbsp;<code>0 &lt; x &lt;= d</code>&nbsp;。</li>
</ul>

<p>除此以外，你从下标&nbsp;<code>i</code> 跳到下标 <code>j</code>&nbsp;需要满足：<code>arr[i] &gt; arr[j]</code>&nbsp;且 <code>arr[i] &gt; arr[k]</code>&nbsp;，其中下标&nbsp;<code>k</code>&nbsp;是所有 <code>i</code>&nbsp;到 <code>j</code>&nbsp;之间的数字（更正式的，<code>min(i, j) &lt; k &lt; max(i, j)</code>）。</p>
<p>你可以选择数组的任意下标开始跳跃。请你返回你 <strong>最多</strong>&nbsp;可以访问多少个下标。</p>
<p>请注意，任何时刻你都不能跳到数组的外面。</p>
<p>&nbsp;</p>
<p><strong>示例 1：</strong></p>
<p><img alt="" src="./meta-chart.jpeg" style="height: 419px; width: 633px;"></p>
<pre><strong>输入：</strong>arr = [6,4,14,6,8,13,9,7,10,6,12], d = 2
<strong>输出：</strong>4
<strong>解释：</strong>你可以从下标 10 出发，然后如上图依次经过 10 --&gt; 8 --&gt; 6 --&gt; 7 。
注意，如果你从下标 6 开始，你只能跳到下标 7 处。你不能跳到下标 5 处因为 13 &gt; 9 。你也不能跳到下标 4 处，因为下标 5 在下标 4 和 6 之间且 13 &gt; 9 。
类似的，你不能从下标 3 处跳到下标 2 或者下标 1 处。
</pre>

<p><strong>示例 2：</strong></p>
<pre><strong>输入：</strong>arr = [3,3,3,3,3], d = 3
<strong>输出：</strong>1
<strong>解释：</strong>你可以从任意下标处开始且你永远无法跳到任何其他坐标。
</pre>

<p><strong>示例 3：</strong></p>
<pre><strong>输入：</strong>arr = [7,6,5,4,3,2,1], d = 1
<strong>输出：</strong>7
<strong>解释：</strong>从下标 0 处开始，你可以按照数值从大到小，访问所有的下标。
</pre>

<p><strong>示例 4：</strong></p>
<pre><strong>输入：</strong>arr = [7,1,7,1,7,1], d = 2
<strong>输出：</strong>2
</pre>

<p><strong>示例 5：</strong></p>
<pre><strong>输入：</strong>arr = [66], d = 1
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>
<p><strong>提示：</strong></p>
<ul>
	<li><code>1 &lt;= arr.length &lt;= 1000</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 10^5</code></li>
	<li><code>1 &lt;= d &lt;= arr.length</code></li>
</ul>

​            

---
### 思路
```

```
[发布的题解](https://leetcode-cn.com/problems/jump-game-v/solution/5331-by-ikaruga/)


### 答题
``` C++
void maxJumps(vector<int>& arr, int d, int cur, vector<int>& steps, int& ans)
{
	int l = max(0, cur - d);
	int r = min((int)arr.size() - 1, cur + d);

	int step = 0;
	for (int dirction = -1; dirction <= 1; dirction += 2)
	{
		int h = arr[cur];
		for (int i = cur; i <= r && i >= l; i += dirction)
		{
			if (i == cur) continue;
			if (h <= arr[i]) break;

			if (steps[i] == -1)
			{
				maxJumps(arr, d, i, steps, ans);
			}
			step = max(step, steps[i]);
		}
	}
	steps[cur] = step + 1;
	ans = max(ans, steps[cur]);
}

int maxJumps(vector<int>& arr, int d) 
{
	vector<int> steps(arr.size(), -1);
	int ans = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		maxJumps(arr, d, i, steps, ans);
	}
	return ans;
}
```




