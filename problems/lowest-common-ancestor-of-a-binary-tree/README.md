# `（中等）` [236.lowest-common-ancestor-of-a-binary-tree 二叉树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)

### 题目描述
<p>给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。</p>

<p><a href="https://baike.baidu.com/item/%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88/8918834?fr=aladdin">百度百科</a>中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（<strong>一个节点也可以是它自己的祖先</strong>）。”</p>

<p>例如，给定如下二叉树:&nbsp; root =&nbsp;[3,5,1,6,2,0,8,null,null,7,4]</p>

<p><img style="height: 190px; width: 200px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/15/binarytree.png" alt=""></p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
<strong>输出:</strong> 3
<strong>解释: </strong>节点 <code>5 </code>和节点 <code>1 </code>的最近公共祖先是节点 <code>3。</code>
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
<strong>输出:</strong> 5
<strong>解释: </strong>节点 <code>5 </code>和节点 <code>4 </code>的最近公共祖先是节点 <code>5。</code>因为根据定义最近公共祖先节点可以为节点本身。
</pre>

<p>&nbsp;</p>

<p><strong>说明:</strong></p>

<ul>
	<li>所有节点的值都是唯一的。</li>
	<li>p、q 为不同节点且均存在于给定的二叉树中。</li>
</ul>


---
### 思路
```
如果左子树找到了，而右子树没找到，说明右边没有，可以排除右边。  
反之右边也是。
递归推进。
如果两边都找到，说明这里是公共祖先。
```

### 答题
``` C++
bool findOne(TreeNode *root, TreeNode *p, TreeNode *q)
{
	if (root == nullptr || p == nullptr || q == nullptr) return false;
	if (root != p && root != q) return findOne(root->left, p, q) || findOne(root->right, p, q);
	return true;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
	if (root == nullptr || p == nullptr || q == nullptr) return nullptr;
	if (root != p && root != q)
	{
		bool l = findOne(root->left, p, q);
		bool r = findOne(root->right, p, q);
		if (l && !r) return lowestCommonAncestor(root->left, p, q);
		if (!l && r) return lowestCommonAncestor(root->right, p, q);
	}
	return root;
}
```

### 其它
```
如果这个结点为空，或者是pq之一，返回。
递归左子树，如果left不为空，并且也不是pq，说明找到的是公共祖先，返回。
递归右子树，如果left（排除上一句的可能，肯定是pq之一，或者为空）和right（公共祖先，或者pq之一，或者为空）都不为空，说明两边都是pq之一，那么root是公共祖先。
最后，剩下的情况为，left和right有一边是空，另一边是公共祖先。
```

``` C++
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (!root || p == root || q == root) return root;
	TreeNode *left = lowestCommonAncestor(root->left, p, q);
	if (left && left != p && left != q) return left;
	TreeNode *right = lowestCommonAncestor(root->right, p, q);
	if (left && right) return root;
	return left ? left : right;
}
```

