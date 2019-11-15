# `（中等）` [701.insert-into-a-binary-search-tree 二叉搜索树中的插入操作](https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/)

### 题目描述
<p>给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 保证原始二叉搜索树中不存在新值。</p>

<p>注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回任意有效的结果。</p>

<p>例如,&nbsp;</p>

<pre>给定二叉搜索树:

        4
       / \
      2   7
     / \
    1   3

和 插入的值: 5
</pre>

<p>你可以返回这个二叉搜索树:</p>

<pre>         4
       /   \
      2     7
     / \   /
    1   3 5
</pre>

<p>或者这个树也是有效的:</p>

<pre>         5
       /   \
      2     7
     / \   
    1   3
         \
          4
</pre>


---
### 思路
```
```

### 答题
``` C++
TreeNode* insertIntoBST(TreeNode* root, int val)
{
	TreeNode *pNode = root;
	while (pNode != nullptr)
	{
		if (val == pNode->val) return root;
		if (val < pNode->val)
		{
			if (pNode->left == nullptr) pNode->left = new TreeNode(val);
			pNode = pNode->left;
		}
		else
		{
			if (pNode->right == nullptr) pNode->right = new TreeNode(val);
			pNode = pNode->right;
		}
	}
	return root;
}
```
