# `（中等）` [5815.maximum-number-of-points-with-cost 扣分后的最大得分](https://leetcode-cn.com/problems/maximum-number-of-points-with-cost/)

[contest](https://leetcode-cn.com/contest/weekly-contest-250/problems/maximum-number-of-points-with-cost/)

### 题目描述
<div class="notranslate"><p>给你一个&nbsp;<code>m x n</code>&nbsp;的整数矩阵&nbsp;<code>points</code>&nbsp;（下标从 <strong>0</strong>&nbsp;开始）。一开始你的得分为 <code>0</code>&nbsp;，你想最大化从矩阵中得到的分数。</p>

<p>你的得分方式为：<strong>每一行</strong>&nbsp;中选取一个格子，选中坐标为&nbsp;<code>(r, c)</code>&nbsp;的格子会给你的总得分 <strong>增加</strong>&nbsp;<code>points[r][c]</code>&nbsp;。</p>
<p>然而，相邻行之间被选中的格子如果隔得太远，你会失去一些得分。对于相邻行&nbsp;<code>r</code> 和&nbsp;<code>r + 1</code>&nbsp;（其中&nbsp;<code>0 &lt;= r &lt; m - 1</code>），选中坐标为&nbsp;<code>(r, c<sub>1</sub>)</code> 和&nbsp;<code>(r + 1, c<sub>2</sub>)</code>&nbsp;的格子，你的总得分&nbsp;<b>减少</b>&nbsp;<code>abs(c<sub>1</sub> - c<sub>2</sub>)</code>&nbsp;。</p>
<p>请你返回你能得到的 <strong>最大</strong>&nbsp;得分。</p>
<p><code>abs(x)</code>&nbsp;定义为：</p>
<ul>
	<li>如果&nbsp;<code>x &gt;= 0</code>&nbsp;，那么值为&nbsp;<code>x</code>&nbsp;。</li>
	<li>如果&nbsp;<code>x &lt;&nbsp;0</code>&nbsp;，那么值为 <code>-x</code>&nbsp;。</li>
</ul>

<p>&nbsp;</p>
<p><strong>示例 1：</strong></p>
<img style="width: 300px; height: 300px;" src="https://assets.leetcode.com/uploads/2021/07/12/screenshot-2021-07-12-at-13-40-26-diagram-drawio-diagrams-net.png" alt="">
<pre><b>输入：</b>points = [[1,2,3],[1,5,1],[3,1,1]]
<b>输出：</b>9
<strong>解释：</strong>
蓝色格子是最优方案选中的格子，坐标分别为 (0, 2)，(1, 1) 和 (2, 0) 。
你的总得分增加 3 + 5 + 3 = 11 。
但是你的总得分需要扣除 abs(2 - 1) + abs(1 - 0) = 2 。
你的最终得分为 11 - 2 = 9 。
</pre>

<p><strong>示例 2：</strong></p>
<img style="width: 200px; height: 299px;" src="https://assets.leetcode.com/uploads/2021/07/12/screenshot-2021-07-12-at-13-42-14-diagram-drawio-diagrams-net.png" alt="">
<pre><b>输入：</b>points = [[1,5],[2,3],[4,2]]
<b>输出：</b>11
<strong>解释：</strong>
蓝色格子是最优方案选中的格子，坐标分别为 (0, 1)，(1, 1) 和 (2, 0) 。
你的总得分增加 5 + 3 + 4 = 12 。
但是你的总得分需要扣除 abs(1 - 1) + abs(1 - 0) = 1 。
你的最终得分为 12 - 1 = 11 。
</pre>

<p>&nbsp;</p>
<p><strong>提示：</strong></p>
<ul>
	<li><code>m == points.length</code></li>
	<li><code>n == points[r].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= points[r][c] &lt;= 10<sup>5</sup></code></li>
</ul>
</div>

---
### 思路
```

```

[发布的题解](https://leetcode-cn.com/problems/maximum-number-of-points-with-cost/solution/maximum-number-of-points-with-cost-by-ik-0r3g/)

### 答题
``` C++
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
		vector<long long> dp(points[0].size(), 0);
        vector<long long> pre(points[0].size(), 0);
		for (int i = 0; i < dp.size(); i++) {
            pre[i] = (long long)points[0][i];
			dp[i] = (long long)points[0][i];
		}

		for (int i = 1; i < points.size(); i++) {
			change(dp);
			swap(dp, pre);
			for (int j = 0; j < points[i].size(); j++) {
				dp[j] = max(dp[j], (long long)points[i][j] + pre[j]);
			}
		}
		return *max_element(dp.begin(), dp.end());
    }

	void change(vector<long long>& dp) {
		for (int i = 1; i < dp.size(); i++) {
			dp[i] = max(dp[i], dp[i - 1] - 1);
		}
		for (int i = (int)dp.size() - 2; ~i; i--) {
			dp[i] = max(dp[i], dp[i + 1] - 1);
		}
	}
};
```




