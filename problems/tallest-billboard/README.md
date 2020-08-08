# `（困难）` [956.tallest-billboard 最高的广告牌](https://leetcode-cn.com/problems/tallest-billboard/)

### 题目描述
<p>你正在安装一个广告牌，并希望它高度最大。这块广告牌将有两个钢制支架，两边各一个。每个钢支架的高度必须相等。</p>

<p>你有一堆可以焊接在一起的钢筋 <code>rods</code>。举个例子，如果钢筋的长度为 1、2 和 3，则可以将它们焊接在一起形成长度为 6 的支架。</p>

<p>返回广告牌的最大可能安装高度。如果没法安装广告牌，请返回 0。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>[1,2,3,6]
<strong>输出：</strong>6
<strong>解释：</strong>我们有两个不相交的子集 {1,2,3} 和 {6}，它们具有相同的和 sum = 6。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>[1,2,3,4,5,6]
<strong>输出：</strong>10
<strong>解释：</strong>我们有两个不相交的子集 {2,3,5} 和 {4,6}，它们具有相同的和 sum = 10。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>[1,2]
<strong>输出：</strong>0
<strong>解释：</strong>没法安装广告牌，所以返回 0。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>0 <= rods.length <= 20</code></li>
	<li><code>1 <= rods[i] <= 1000</code></li>
	<li><code>钢筋的长度总和最多为 5000</code></li>
</ol>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
		if (rods.size() < 2) return 0;
		int sum = accumulate(rods.begin(), rods.end(), 0);
		sort(rods.rbegin(), rods.rend());
		dfs(rods, 0, rods[0], 0, sum - rods[0]);
		dfs(rods, 0, 0, 0, sum - rods[0]);
		return ans;
    }

	void dfs(vector<int>& rods, int idx, int left, int right, int remain) {
		if (abs(left - right) > remain || (left + right + remain) <= ans * 2) return;
		
		if (left == right) {
			ans = max(ans, left);
		}

		if (++idx == rods.size()) return;

		remain -= rods[idx];
		dfs(rods, idx, left + rods[idx], right, remain);
		dfs(rods, idx, left, right + rods[idx], remain);
		dfs(rods, idx, left, right, remain);
	}

private:
	int ans = 0;
};
```




