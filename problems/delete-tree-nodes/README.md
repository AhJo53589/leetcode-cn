# `（中等）` [1273.delete-tree-nodes 删除树节点](https://leetcode-cn.com/problems/delete-tree-nodes/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-14/problems/delete-tree-nodes/)

### 题目描述
<p>给你一棵以节点 0 为根节点的树，定义如下：</p>

<ul>
	<li>节点的总数为&nbsp;<code>nodes</code>&nbsp;个；</li>
	<li>第&nbsp;<code>i</code> 个节点的值为&nbsp;<code>value[i]</code>&nbsp;；</li>
	<li>第&nbsp;<code>i</code> 个节点的父节点是&nbsp;<code>parent[i]</code>&nbsp;。</li>
</ul>

<p>请你删除节点值之和为 0 的每一棵子树。</p>

<p>在完成所有删除之后，返回树中剩余节点的数目。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<p><img alt="" src="./1421_sample_1.png" style="height: 347px; width: 403px;"></p>

<pre><strong>输入：</strong>nodes = 7, parent = [-1,0,0,1,2,2,2], value = [1,-2,4,0,-2,-1,-1]
<strong>输出：</strong>2
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nodes &lt;= 10^4</code></li>
	<li><code>-10^5 &lt;= value[i] &lt;= 10^5</code></li>
	<li><code>parent.length == nodes</code></li>
	<li><code>parent[0] == -1</code>&nbsp;表示节点 <code>0</code> 是树的根。</li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) 
{
	int ans = parent.size();

	vector<int> cnt(parent.size(), 0);
	vector<int> del(parent.size(), 0);
	vector<int> visited(parent.size(), 0);
	vector<int> sum(parent.size(), 0);
	for (auto i = 0; i < parent.size(); i++)
	{
		if (parent[i] != -1)
		{
			cnt[parent[i]]++;
			del[parent[i]]++;
		}
	}

	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < parent.size(); i++)
		{
			if (cnt[i] > 0)
			{
				flag = true;
				continue;
			}
			if (visited[i]++ != 0) continue;

			sum[i] += value[i];
			if (parent[i] != -1)
			{
				cnt[parent[i]]--;
				sum[parent[i]] += sum[i];
			}

			if (sum[i] == 0)
			{
				ans -= del[i] + 1;
			}
			if (parent[i] != -1)
			{
				del[parent[i]] = (sum[i] == 0) ? del[parent[i]] - 1 : del[parent[i]] + del[i];
			}
		}
	}

	return ans;
}
```




