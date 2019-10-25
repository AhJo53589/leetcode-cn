# `（中等）`  [230.kth-smallest-element-in-a-bst 二叉搜索树中第K小的元素](https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/)

### 题目描述
<p>给定一个二叉搜索树，编写一个函数&nbsp;<code>kthSmallest</code>&nbsp;来查找其中第&nbsp;<strong>k&nbsp;</strong>个最小的元素。</p>

<p><strong>说明：</strong><br>
你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
&nbsp;  2
<strong>输出:</strong> 1</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
<strong>输出:</strong> 3</pre>

<p><strong>进阶：</strong><br>
如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化&nbsp;<code>kthSmallest</code>&nbsp;函数？</p>


---
### 思路
```
```

### 答题
``` C++
void InOrder(TreeNode *root, int &k, int &val)
{
	if (k == 0) return;
	if (root == nullptr) return;
	if (root->left != nullptr) InOrder(root->left, k, val);
	if (k-- == 1) val = root->val;
	if (root->right != nullptr) InOrder(root->right, k, val);
}

int kthSmallest(TreeNode* root, int k) 
{
	int val;
	InOrder(root, k, val);
	return val;
}
```

### 其它
``` C++
```

