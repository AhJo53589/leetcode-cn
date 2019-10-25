# `（困难）`  [145.binary-tree-postorder-traversal 二叉树的后序遍历](https://leetcode-cn.com/problems/binary-tree-postorder-traversal/)

### 题目描述
<p>给定一个二叉树，返回它的 <em>后序&nbsp;</em>遍历。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> [1,null,2,3]  
   1
    \
     2
    /
   3 

<strong>输出:</strong> [3,2,1]</pre>

<p><strong>进阶:</strong>&nbsp;递归算法很简单，你可以通过迭代算法完成吗？</p>


---
### 思路
```
```

### 答题
``` C++
vector<int> postorderTraversal(TreeNode* root)
{
	if (root == nullptr) return {};
	vector<int> ret;
	vector<int> left;
	vector<int> right;

	if (root->left != nullptr) left = postorderTraversal(root->left);
	ret.insert(ret.end(), left.begin(), left.end());
	if (root->right != nullptr) right = postorderTraversal(root->right);
	ret.insert(ret.end(), right.begin(), right.end());
	ret.push_back(root->val);
	return ret;
}
```
