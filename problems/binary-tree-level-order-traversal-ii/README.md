# `（简单）` [107.binary-tree-level-order-traversal-ii 二叉树的层次遍历 II](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/)

### 题目描述
<p>给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）</p>

<p>例如：<br>
给定二叉树 <code>[3,9,20,null,null,15,7]</code>,</p>

<pre>    3
   / \
  9  20
    /  \
   15   7
</pre>

<p>返回其自底向上的层次遍历为：</p>

<pre>[
  [15,7],
  [9,20],
  [3]
]
</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/solution/107-by-ikaruga/)

### 答题
``` C++
void levelOrderBottom(queue<TreeNode *> que, vector<vector<int>> &ans)
{
	if (que.empty()) return;
	queue<TreeNode *> queNext;
	vector<int> vec;
	while (!que.empty())
	{
		TreeNode *pNode = que.front();
		que.pop();
		vec.push_back(pNode->val);
		if (pNode->left != nullptr) queNext.push(pNode->left);	
		if (pNode->right != nullptr) queNext.push(pNode->right);
	}
	levelOrderBottom(queNext, ans);
	ans.push_back(vec);
}

vector<vector<int>> levelOrderBottom(TreeNode* root) 
{
	vector<vector<int>> ans;
	queue<TreeNode *> q;
	if (root != nullptr) q.push(root);
	levelOrderBottom(q, ans);
	return ans;
}
```

