# `（困难）`  [124.binary-tree-maximum-path-sum 二叉树中的最大路径和](https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/)

### 题目描述
<p>给定一个<strong>非空</strong>二叉树，返回其最大路径和。</p>

<p>本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径<strong>至少包含一个</strong>节点，且不一定经过根节点。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> [1,2,3]

       <strong>1</strong>
      <strong>/ \</strong>
     <strong>2</strong>   <strong>3</strong>

<strong>输出:</strong> 6
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> [-10,9,20,null,null,15,7]

&nbsp;  -10
&nbsp; &nbsp;/ \
&nbsp; 9 &nbsp;<strong>20</strong>
&nbsp; &nbsp; <strong>/ &nbsp;\</strong>
&nbsp; &nbsp;<strong>15 &nbsp; 7</strong>

<strong>输出:</strong> 42</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/solution/er-cha-shu-zhong-de-zui-da-lu-jing-he-by-ikaruga/)

### 答题
``` C++
int maxPathSum(TreeNode* root, int &val)
{
	if (root == nullptr) return 0;
	int left = maxPathSum(root->left, val);
	int right = maxPathSum(root->right, val);
	int lmr = root->val + max(0, left) + max(0, right);
	int ret = root->val + max(0, max(left, right));
	val = max(val, max(lmr, ret));
	return ret;
}

int maxPathSum(TreeNode* root) 
{
	int val = INT_MIN;
	maxPathSum(root, val);
	return val;
}
```
