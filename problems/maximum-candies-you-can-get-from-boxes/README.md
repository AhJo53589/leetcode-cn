# `（困难）` [1298.maximum-candies-you-can-get-from-boxes 你能从盒子里获得的最大糖果数](https://leetcode-cn.com/problems/maximum-candies-you-can-get-from-boxes/)

[contest](https://leetcode-cn.com/contest/weekly-contest-168/problems/maximum-candies-you-can-get-from-boxes/)

### 题目描述
<p>给你&nbsp;<code>n</code>&nbsp;个盒子，每个盒子的格式为&nbsp;<code>[status, candies, keys, containedBoxes]</code>&nbsp;，其中：</p>

<ul>
	<li>状态字&nbsp;<code>status[i]</code>：整数，如果&nbsp;<code>box[i]</code>&nbsp;是开的，那么是 <strong>1&nbsp;</strong>，否则是 <strong>0&nbsp;</strong>。</li>
	<li>糖果数&nbsp;<code>candies[i]</code>: 整数，表示&nbsp;<code>box[i]</code> 中糖果的数目。</li>
	<li>钥匙&nbsp;<code>keys[i]</code>：数组，表示你打开&nbsp;<code>box[i]</code>&nbsp;后，可以得到一些盒子的钥匙，每个元素分别为该钥匙对应盒子的下标。</li>
	<li>内含的盒子&nbsp;<code>containedBoxes[i]</code>：整数，表示放在&nbsp;<code>box[i]</code>&nbsp;里的盒子所对应的下标。</li>
</ul>

<p>给你一个&nbsp;<code>initialBoxes</code> 数组，表示你现在得到的盒子，你可以获得里面的糖果，也可以用盒子里的钥匙打开新的盒子，还可以继续探索从这个盒子里找到的其他盒子。</p>

<p>请你按照上述规则，返回可以获得糖果的 <strong>最大数目&nbsp;</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>status = [1,0,1,0], candies = [7,5,4,100], keys = [[],[],[1],[]], containedBoxes = [[1,2],[3],[],[]], initialBoxes = [0]
<strong>输出：</strong>16
<strong>解释：
</strong>一开始你有盒子 0 。你将获得它里面的 7 个糖果和盒子 1 和 2。
盒子 1 目前状态是关闭的，而且你还没有对应它的钥匙。所以你将会打开盒子 2 ，并得到里面的 4 个糖果和盒子 1 的钥匙。
在盒子 1 中，你会获得 5 个糖果和盒子 3 ，但是你没法获得盒子 3 的钥匙所以盒子 3 会保持关闭状态。
你总共可以获得的糖果数目 = 7 + 4 + 5 = 16 个。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>status = [1,0,0,0,0,0], candies = [1,1,1,1,1,1], keys = [[1,2,3,4,5],[],[],[],[],[]], containedBoxes = [[1,2,3,4,5],[],[],[],[],[]], initialBoxes = [0]
<strong>输出：</strong>6
<strong>解释：
</strong>你一开始拥有盒子 0 。打开它你可以找到盒子 1,2,3,4,5 和它们对应的钥匙。
打开这些盒子，你将获得所有盒子的糖果，所以总糖果数为 6 个。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>status = [1,1,1], candies = [100,1,100], keys = [[],[0,2],[]], containedBoxes = [[],[],[]], initialBoxes = [1]
<strong>输出：</strong>1
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>status = [1], candies = [100], keys = [[]], containedBoxes = [[]], initialBoxes = []
<strong>输出：</strong>0
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>status = [1,1,1], candies = [2,3,2], keys = [[],[],[]], containedBoxes = [[],[],[]], initialBoxes = [2,1,0]
<strong>输出：</strong>7
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= status.length &lt;= 1000</code></li>
	<li><code>status.length == candies.length == keys.length == containedBoxes.length == n</code></li>
	<li><code>status[i]</code> 要么是&nbsp;<code>0</code>&nbsp;要么是&nbsp;<code>1</code> 。</li>
	<li><code>1 &lt;= candies[i] &lt;= 1000</code></li>
	<li><code>0 &lt;= keys[i].length &lt;= status.length</code></li>
	<li><code>0 &lt;= keys[i][j] &lt; status.length</code></li>
	<li><code>keys[i]</code>&nbsp;中的值都是互不相同的。</li>
	<li><code>0 &lt;= containedBoxes[i].length &lt;= status.length</code></li>
	<li><code>0 &lt;= containedBoxes[i][j] &lt; status.length</code></li>
	<li><code>containedBoxes[i]</code>&nbsp;中的值都是互不相同的。</li>
	<li>每个盒子最多被一个盒子包含。</li>
	<li><code>0 &lt;= initialBoxes.length&nbsp;&lt;= status.length</code></li>
	<li><code>0 &lt;= initialBoxes[i] &lt; status.length</code></li>
</ul>

            

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/maximum-candies-you-can-get-from-boxes/solution/5294-by-ikaruga/)

### 答题
``` C++
vector<int> getHaveBoxes(vector<int>& haveStatus)
{
	vector<int> ret;
	for (auto i = 0; i < haveStatus.size(); i++)
	{
		if (haveStatus[i] == 1)
		{
			ret.push_back(i);
		}
	}
	return ret;
}

int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) 
{
	vector<int> haveStatus(status.size(), 0);
	for (auto n : initialBoxes) haveStatus[n] = 1;
	vector<int> keyStatus(status.size(), 0);

	int ans = 0;

	bool flag = true;
	while (flag)
	{
		flag = false;

		auto have = getHaveBoxes(haveStatus);
		if (have.empty()) break;

		for (auto i : have)
		{
			if (status[i] == 1 || keyStatus[i] == 1)
			{
				flag = true;
				haveStatus[i] = 2;

				ans += candies[i];
				for (auto k : keys[i])
				{
					keyStatus[k] = 1;
				}
				for (auto c : containedBoxes[i])
				{
					haveStatus[c] = 1;
				}
			}
		}
	}
	return ans;
}
```




