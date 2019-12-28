# `（中等）` [5153.deepest-leaves-sum 层数最深叶子节点的和](https://leetcode-cn.com/problems/deepest-leaves-sum/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-16/problems/deepest-leaves-sum/)

### 题目描述
<p>给你一棵二叉树，请你返回层数最深的叶子节点的和。</p>
<p>&nbsp;</p>
<p><strong>示例：</strong></p>
<p><strong><img alt="" src="./1483_ex1.png" style="height: 265px; width: 273px;"></strong></p>
<pre><strong>输入：</strong>root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
<strong>输出：</strong>15
</pre>

<p>&nbsp;</p>
<p><strong>提示：</strong></p>
<ul>
	<li>树中节点数目在&nbsp;<code>1</code>&nbsp;到&nbsp;<code>10^4</code>&nbsp;之间。</li>
	<li>每个节点的值在&nbsp;<code>1</code>&nbsp;到&nbsp;<code>100</code> 之间。</li>
</ul>

​            

---
### 思路
```

```



### 答题
``` C++
int deepestLeavesSum(TreeNode* root) 
{
	if (root == nullptr) return 0;

	int max_level = 0;
	int ans = 0;

	queue<pair<TreeNode*, int>> que;
	que.push({ root, 0 });

	while (!que.empty())
	{
		auto q = que.front();
		que.pop();

		if (max_level != q.second)
		{
			max_level = q.second;
			ans = 0;
		}
		ans += q.first->val;

		if (q.first->left != nullptr)
		{
			que.push({ q.first->left, q.second + 1 });
		}
		if (q.first->right != nullptr)
		{
			que.push({ q.first->right, q.second + 1 });
		}
	}

	return ans;
}
```




