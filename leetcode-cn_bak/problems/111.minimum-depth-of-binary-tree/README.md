# `（简单）`  [111.minimum-depth-of-binary-tree 二叉树的最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/)

### 题目描述
<p>给定一个二叉树，找出其最小深度。</p>

<p>最小深度是从根节点到最近叶子节点的最短路径上的节点数量。</p>

<p><strong>说明:</strong>&nbsp;叶子节点是指没有子节点的节点。</p>

<p><strong>示例:</strong></p>

<p>给定二叉树&nbsp;<code>[3,9,20,null,null,15,7]</code>,</p>

<pre>    3
   / \
  9  20
    /  \
   15   7</pre>

<p>返回它的最小深度 &nbsp;2.</p>


---
### 思路
```
```

### 答题
``` C++
int minDepth(TreeNode* root) 
{
	if (root == nullptr) return 0;
	if (root->left == nullptr && root->right == nullptr) return 1;
	int left = (root->left == nullptr) ? INT_MAX : minDepth(root->left);
	int right = (root->right == nullptr) ? INT_MAX : minDepth(root->right);
	return min(left, right) + 1;
}
```


