# `（中等）` [1245.tree-diameter 树的直径](https://leetcode-cn.com/problems/tree-diameter/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-12/problems/tree-diameter/)

### 题目描述
<p>我们用一个由所有「边」组成的数组 <code>edges</code>&nbsp;来表示一棵无向树，其中&nbsp;<code>edges[i] = [u, v]</code>&nbsp;表示节点&nbsp;<code>u</code> 和 <code>v</code>&nbsp;之间的双向边。</p>

<p>树上的节点都已经用&nbsp;<code>{0, 1, ..., edges.length}</code>&nbsp;中的数做了标记，每个节点上的标记都是独一无二的。</p>

<p>给你这棵「无向树」，请你测算并返回它的「直径」：这棵树上最长简单路径的 <strong>边数</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/10/31/1397_example_1.png" style="height: 233px; width: 226px;"></p>

<pre><strong>输入：</strong>edges = [[0,1],[0,2]]
<strong>输出：</strong>2
<strong>解释：</strong>
这棵树上最长的路径是 1 - 0 - 2，边数为 2。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/10/31/1397_example_2.png" style="height: 316px; width: 350px;"></p>

<pre><strong>输入：</strong>edges = [[0,1],[1,2],[2,3],[1,4],[4,5]]
<strong>输出：</strong>4
<strong>解释： </strong>
这棵树上最长的路径是 3 - 2 - 1 - 4 - 5，边数为 4。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= edges.length &lt;&nbsp;10^4</code></li>
	<li><code>edges[i][0] != edges[i][1]</code></li>
	<li><code>0 &lt;= edges[i][j] &lt;= edges.length</code></li>
	<li><code>edges</code>&nbsp;会形成一棵无向树</li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
pair<int, int> bfs(unordered_map<int, vector<int>> &r, int start)
{
	vector<int> visited(r.size(), - 1);

	queue<int> q;
	q.push(start);
	visited[start] = 0;

	pair<int, int> ret;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		ret.first = x;
		ret.second = visited[x];

		for (auto &y : r[x])
		{
			if (visited[y] == -1)
			{
				visited[y] = visited[x] + 1;
				q.push(y);
			}
		}
	}
	return ret;
}

int treeDiameter(vector<vector<int>>& edges)
{
	sort(edges.begin(), edges.end());
	unordered_map<int, vector<int>> route;
	for (auto n : edges)
	{
		route[n[0]].push_back(n[1]);
		route[n[1]].push_back(n[0]);
	}

	auto ans = bfs(route, 0);
	ans = bfs(route, ans.first);
	return ans.second;
}

```




