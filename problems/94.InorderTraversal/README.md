# `（中等）`  [94.InorderTraversal 二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)

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
	vector<int> vRet;
	if (root == NULL) return vRet;

	vector<int> vTemp;
	vTemp = inorderTraversal(root->left);
	vRet.insert(vRet.end(), vTemp.begin(), vTemp.end());
	vRet.push_back(root->val);
	vTemp = inorderTraversal(root->right);
	vRet.insert(vRet.end(), vTemp.begin(), vTemp.end());
	return vRet;
}
``` 