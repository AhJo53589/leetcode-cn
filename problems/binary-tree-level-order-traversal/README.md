# `（中等）` [102.binary-tree-level-order-traversal 二叉树的层次遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)

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
vector<vector<int>> levelOrder(TreeNode* root)
{
	if (root == nullptr) return {};
	vector<vector<int>> ans;
	queue<TreeNode *> que[2];
	int seq = 0;

	que[seq].push(root);
	while (!(que[0].empty() && que[1].empty()))
	{
		int seq_next = (seq + 1) % 2;
		vector<int> num;
		while (!que[seq].empty())
		{
			TreeNode *pNode = que[seq].front();
			que[seq].pop();
			num.push_back(pNode->val);

			if (pNode->left != nullptr) que[seq_next].push(pNode->left);
			if (pNode->right != nullptr) que[seq_next].push(pNode->right);
		}
		ans.push_back(num);
		seq = seq_next;
	}
	return ans;
}
```

### 其它
``` C++
```

