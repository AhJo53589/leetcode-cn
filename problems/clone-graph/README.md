# `（中等）` [133.clone-graph 克隆图](https://leetcode-cn.com/problems/clone-graph/)

### 题目描述
<p>给定无向<a href="https://baike.baidu.com/item/连通图/6460995?fr=aladdin"><strong>连通</strong></a>图中一个节点的引用，返回该图的<a href="https://baike.baidu.com/item/深拷贝/22785317?fr=aladdin"><strong>深拷贝</strong></a>（克隆）。图中的每个节点都包含它的值 <code>val</code>（<code>Int</code>） 和其邻居的列表（<code>list[Node]</code>）。</p>

<p><strong>示例：</strong></p>

<p><img style="height: 149px; width: 200px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/02/23/113_sample.png" alt=""></p>

<pre><strong>输入：
</strong>{"$id":"1","neighbors":[{"$id":"2","neighbors":[{"$ref":"1"},{"$id":"3","neighbors":[{"$ref":"2"},{"$id":"4","neighbors":[{"$ref":"3"},{"$ref":"1"}],"val":4}],"val":3}],"val":2},{"$ref":"4"}],"val":1}

<strong>解释：</strong>
节点 1 的值是 1，它有两个邻居：节点 2 和 4 。
节点 2 的值是 2，它有两个邻居：节点 1 和 3 。
节点 3 的值是 3，它有两个邻居：节点 2 和 4 。
节点 4 的值是 4，它有两个邻居：节点 1 和 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li>节点数介于 1 到 100 之间。</li>
	<li>无向图是一个<a href="https://baike.baidu.com/item/简单图/1680528?fr=aladdin">简单图</a>，这意味着图中没有重复的边，也没有自环。</li>
	<li>由于图是无向的，如果节点 <em>p</em> 是节点 <em>q</em> 的邻居，那么节点 <em>q</em> 也必须是节点 <em>p</em>&nbsp;的邻居。</li>
	<li>必须将<strong>给定节点的拷贝</strong>作为对克隆图的引用返回。</li>
</ol>




---
### 思路
``` 
```


### 答题
``` C++
Node* cloneGraph(Node* node) 
{
	if (node == NULL) return NULL;

	map<Node *, Node *> visited;
	stack<Node *> s;

	s.push(node);
	while (!s.empty())
	{
		Node *cur = s.top();
		s.pop();
		if (visited.count(cur) == 0)
		{
			Node *pNew = new Node();
			visited[cur] = pNew;
			for (auto n : cur->neighbors)
			{
				s.push(n);
			}
		}
	}

	for (auto i = visited.begin(); i != visited.end(); i++)
	{
		(i->second)->val = (i->first)->val;
		for (auto n : (i->first)->neighbors)
		{
			(i->second)->neighbors.push_back(visited[n]);
		}
	}

	return visited[node];
}
``` 


### 其它
可以对比一下我的代码和别人的代码。  
虽然思路可以说一样，但是别人的写的更好。  

``` C++
Node* cloneGraph(Node* node) 
{
	unordered_map<Node*, Node*> toCopy;
	return clone(node, toCopy);
}

Node* clone(Node* root, unordered_map<Node*, Node*>& toCopy) 
{
	if (toCopy.find(root) != toCopy.end()) return toCopy[root];
	Node* res = new Node(root->val, vector<Node*>({}));
	toCopy.insert({ root, res });
	for (Node* p : root->neighbors)
		res->neighbors.push_back(clone(p, toCopy));
	return res;
}
``` 
