# `（中等）`  [102.LevelOrder 二叉树的层次遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)

### 题目描述
<p>给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。</p>

<p>例如:<br>
给定二叉树:&nbsp;<code>[3,9,20,null,null,15,7]</code>,</p>

<pre>    3
   / \
  9  20
    /  \
   15   7
</pre>

<p>返回其层次遍历结果：</p>

<pre>[
  [3],
  [9,20],
  [15,7]
]
</pre>




---
### 思路
```
```


### 答题
``` C++
vector<vector<int>> levelOrder(TreeNode* root) // 4ms
{
	vector<vector<int> >res;
	if (root == NULL)
		return res;
	queue<TreeNode*> que;
	TreeNode*p;
	que.push(root);
	int level = 0;
	while (!que.empty()) 
	{
		res.push_back(vector<int>());
		int len = que.size();
		while (len--)
		{
			p = que.front();
			que.pop();
			res[level].push_back(p->val);
			if (p->left) que.push(p->left);
			if (p->right) que.push(p->right);
		}
		level++;
	}
	return res;
}
``` 