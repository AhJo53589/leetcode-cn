# `（中等）` [94.binary-tree-inorder-traversal 二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)

### 题目描述
<p>给定一个二叉树，返回它的<em>中序&nbsp;</em>遍历。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> [1,null,2,3]
   1
    \
     2
    /
   3

<strong>输出:</strong> [1,3,2]</pre>

<p><strong>进阶:</strong>&nbsp;递归算法很简单，你可以通过迭代算法完成吗？</p>


---
### 思路
```
```

### 答题
``` C++
vector<int> inorderTraversal(TreeNode* root)
{
	if (root == nullptr) return {};
	vector<int> ret;
	vector<int> left;
	vector<int> right;

	if (root->left != nullptr) left = inorderTraversal(root->left);
	ret.insert(ret.end(), left.begin(), left.end());
	ret.push_back(root->val);
	if (root->right != nullptr) right = inorderTraversal(root->right);
	ret.insert(ret.end(), right.begin(), right.end());
	return ret;
}
```
