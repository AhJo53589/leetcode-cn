# `（中等）` [5330.maximum-product-of-splitted-binary-tree 分裂二叉树的最大乘积](https://leetcode-cn.com/problems/maximum-product-of-splitted-binary-tree/)

[contest](https://leetcode-cn.com/contest/weekly-contest-174/problems/maximum-product-of-splitted-binary-tree/)

### 题目描述
<p>给你一棵二叉树，它的根为&nbsp;<code>root</code> 。请你删除 1 条边，使二叉树分裂成两棵子树，且它们子树和的乘积尽可能大。</p>
<p>由于答案可能会很大，请你将结果对 10^9 + 7 取模后再返回。</p>
<p>&nbsp;</p>
<p><strong>示例 1：</strong></p>
<p><strong><img alt="" src="./sample_1_1699.png" style="height: 200px; width: 495px;"></strong></p>
<pre><strong>输入：</strong>root = [1,2,3,4,5,6]
<strong>输出：</strong>110
<strong>解释：</strong>删除红色的边，得到 2 棵子树，和分别为 11 和 10 。它们的乘积是 110 （11*10）
</pre>

<p><strong>示例 2：</strong></p>
<p><img alt="" src="./sample_2_1699.png" style="height: 200px; width: 495px;"></p>
<pre><strong>输入：</strong>root = [1,null,2,3,4,null,null,5,6]
<strong>输出：</strong>90
<strong>解释：</strong>移除红色的边，得到 2 棵子树，和分别是 15 和 6 。它们的乘积为 90 （15*6）
</pre>

<p><strong>示例 3：</strong></p>
<pre><strong>输入：</strong>root = [2,3,9,10,7,8,6,5,4,11,1]
<strong>输出：</strong>1025
</pre>

<p><strong>示例 4：</strong></p>
<pre><strong>输入：</strong>root = [1,1]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>
<p><strong>提示：</strong></p>
<ul>
	<li>每棵树最多有&nbsp;<code>50000</code>&nbsp;个节点，且至少有&nbsp;<code>2</code>&nbsp;个节点。</li>
	<li>每个节点的值在&nbsp;<code>[1, 10000]</code>&nbsp;之间。</li>
</ul>

​            

---
### 思路
```

```



### 答题
``` C++
int part_sum(TreeNode* root)
{
	if (root == nullptr) return 0;
	root->val += part_sum(root->left) + part_sum(root->right);
	return root->val;
}

void getDiff(TreeNode* root, int full, int& diff)
{
	if (root == nullptr) return;
	int a = full - root->val * 2;
	diff = (abs(a) < abs(diff)) ? a : diff;
	getDiff(root->left, full, diff);
	getDiff(root->right, full, diff);
}

int maxProduct(TreeNode* root) 
{
	if (root == nullptr) return 0;
	root->val += part_sum(root->left) + part_sum(root->right);

	int full = root->val;
	int diff = INT_MAX;
	getDiff(root, full, diff);
	int half = (full + diff) / 2;

	int ans = ((long long)(full - half) * (long long)half) % (long long)(1e9 + 7);
	return ans;
}
```




