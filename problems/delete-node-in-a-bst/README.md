# `（中等）` [450.delete-node-in-a-bst 删除二叉搜索树中的节点](https://leetcode-cn.com/problems/delete-node-in-a-bst/)

### 题目描述
<p>给定一个二叉搜索树的根节点 <strong>root </strong>和一个值 <strong>key</strong>，删除二叉搜索树中的&nbsp;<strong>key&nbsp;</strong>对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。</p>

<p>一般来说，删除节点可分为两个步骤：</p>

<ol>
	<li>首先找到需要删除的节点；</li>
	<li>如果找到了，删除它。</li>
</ol>

<p><strong>说明：</strong> 要求算法时间复杂度为&nbsp;O(h)，h 为树的高度。</p>

<p><strong>示例:</strong></p>

<pre>root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。

一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。

    5
   / \
  4   6
 /     \
2       7

另一个正确答案是 [5,2,6,null,4,null,7]。

    5
   / \
  2   6
   \   \
    4   7
</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/delete-node-in-a-bst/solution/shan-chu-er-cha-sou-suo-shu-zhong-de-jie-dian-by-i/)

### 答题
``` C++
int funDelete(TreeNode **ppNode)
{
	int res = (*ppNode)->val;
	if ((*ppNode)->left == nullptr || (*ppNode)->right == nullptr)
	{
		TreeNode *pChild = ((*ppNode)->left != nullptr) ? (*ppNode)->left : (*ppNode)->right;
		delete (*ppNode);
		*ppNode = pChild;
	}
	else
	{
		TreeNode **ppChild = &((*ppNode)->left->right);
		while ((*ppChild) != nullptr && (*ppChild)->right != nullptr) ppChild = &((*ppChild)->right);
		
		if ((*ppChild) == nullptr)
		{
			ppChild = &((*ppNode)->right->left);
			while ((*ppChild) != nullptr && (*ppChild)->left != nullptr) ppChild = &((*ppChild)->left);
		}

		if ((*ppChild) == nullptr) ppChild = &((*ppNode)->right);

		(*ppNode)->val = funDelete(ppChild);
	}
	return res;
}

TreeNode* deleteNode(TreeNode* root, int key) //执行用时：28 ms
{
	TreeNode **ppNode = &root;
	while ((*ppNode) != nullptr)
	{
		if (key == (*ppNode)->val)
		{
			funDelete(ppNode);
			return root;
		}
		if (key < (*ppNode)->val)
		{
			ppNode = &((*ppNode)->left);
		}
		else
		{
			ppNode = &((*ppNode)->right);
		}
	}
	return root;
}
```

### 其它
``` C++
```

