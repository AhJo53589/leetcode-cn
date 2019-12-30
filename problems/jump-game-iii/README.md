# `（中等）` [1306.jump-game-iii 跳跃游戏 III](https://leetcode-cn.com/problems/jump-game-iii/)

[contest](https://leetcode-cn.com/contest/weekly-contest-169/problems/jump-game-iii/)

### 题目描述
<p>这里有一个非负整数数组&nbsp;<code>arr</code>，你最开始位于该数组的起始下标&nbsp;<code>start</code>&nbsp;处。当你位于下标&nbsp;<code>i</code>&nbsp;处时，你可以跳到&nbsp;<code>i + arr[i]</code> 或者 <code>i - arr[i]</code>。</p>

<p>请你判断自己是否能够跳到对应元素值为 0 的 <strong>任意</strong> 下标处。</p>

<p>注意，不管是什么情况下，你都无法跳到数组之外。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [4,2,3,0,3,1,2], start = 5
<strong>输出：</strong>true
<strong>解释：</strong>
到达值为 0 的下标 3 有以下可能方案： 
下标 5 -&gt; 下标 4 -&gt; 下标 1 -&gt; 下标 3 
下标 5 -&gt; 下标 6 -&gt; 下标 4 -&gt; 下标 1 -&gt; 下标 3 
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [4,2,3,0,3,1,2], start = 0
<strong>输出：</strong>true 
<strong>解释：
</strong>到达值为 0 的下标 3 有以下可能方案： 
下标 0 -&gt; 下标 4 -&gt; 下标 1 -&gt; 下标 3
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [3,0,2,1,2], start = 2
<strong>输出：</strong>false
<strong>解释：</strong>无法到达值为 0 的下标 1 处。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 5 * 10^4</code></li>
	<li><code>0 &lt;= arr[i] &lt;&nbsp;arr.length</code></li>
	<li><code>0 &lt;= start &lt; arr.length</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/jump-game-iii/solution/5297-by-ikaruga/)

### 答题
``` C++
void dfs(vector<int>& arr, int i, vector<bool>& vi, bool& ans)
{
	if (ans) return;
	if (i < 0 || i >= arr.size()) return;
	if (vi[i]) return;
	vi[i] = true;
	if (arr[i] == 0)
	{
		ans = true;
		return;
	}
	dfs(arr, i + arr[i], vi, ans);
	dfs(arr, i - arr[i], vi, ans);
}
    
bool canReach(vector<int>& arr, int start) 
{
	bool ans = false;
	vector<bool> vi(arr.size(), false);
	dfs(arr, start, vi, ans);
	return ans;
}
```




