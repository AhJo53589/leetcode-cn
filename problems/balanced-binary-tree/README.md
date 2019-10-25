# `（简单）` [110.balanced-binary-tree 平衡二叉树](https://leetcode-cn.com/problems/balanced-binary-tree/)

### 题目描述
<p>给定一个二叉树，判断它是否是高度平衡的二叉树。</p>

<p>本题中，一棵高度平衡二叉树定义为：</p>

<blockquote>
<p>一个二叉树<em>每个节点&nbsp;</em>的左右两个子树的高度差的绝对值不超过1。</p>
</blockquote>

<p><strong>示例 1:</strong></p>

<p>给定二叉树 <code>[3,9,20,null,null,15,7]</code></p>

<pre>    3
   / \
  9  20
    /  \
   15   7</pre>

<p>返回 <code>true</code> 。<br>
<br>
<strong>示例 2:</strong></p>

<p>给定二叉树 <code>[1,2,2,3,3,null,null,4,4]</code></p>

<pre>       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
</pre>

<p>返回&nbsp;<code>false</code> 。</p>


---
### 思路
```
注意不能求所有叶子节点的高度差，
而是
一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
```

### 答题
``` C++
int getTreeHeight(TreeNode *pNode)
{
	if (pNode == nullptr) return 0;
	int l = getTreeHeight(pNode->left);
	int r = getTreeHeight(pNode->right);
	if (l == -1 || r == -1 || abs(l - r) > 1) return -1;
	return max(l, r) + 1;
}

bool isBalanced(TreeNode* root)
{
	return getTreeHeight(root) != -1;
}
```
