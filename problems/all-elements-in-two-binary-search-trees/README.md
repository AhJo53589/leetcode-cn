# `（中等）` [1305.all-elements-in-two-binary-search-trees 两棵二叉搜索树中的所有元素](https://leetcode-cn.com/problems/all-elements-in-two-binary-search-trees/)

[contest](https://leetcode-cn.com/contest/weekly-contest-169/problems/all-elements-in-two-binary-search-trees/)

### 题目描述
<p>给你&nbsp;<code>root1</code> 和 <code>root2</code>&nbsp;这两棵二叉搜索树。</p>
<p>请你返回一个列表，其中包含&nbsp;<strong>两棵树&nbsp;</strong>中的所有整数并按 <strong>升序</strong> 排序。.</p>
<p>&nbsp;</p>
<p><strong>示例 1：</strong></p>
<p><img src="./q2-e1.png" alt=""></p>
<pre><strong>输入：</strong>root1 = [2,1,4], root2 = [1,0,3]
<strong>输出：</strong>[0,1,1,2,3,4]
</pre>

<p><strong>示例 2：</strong></p>
<pre><strong>输入：</strong>root1 = [0,-10,10], root2 = [5,1,7,0,2]
<strong>输出：</strong>[-10,0,0,1,2,5,7,10]
</pre>

<p><strong>示例 3：</strong></p>
<pre><strong>输入：</strong>root1 = [], root2 = [5,1,7,0,2]
<strong>输出：</strong>[0,1,2,5,7]
</pre>

<p><strong>示例 4：</strong></p>
<pre><strong>输入：</strong>root1 = [0,-10,10], root2 = []
<strong>输出：</strong>[-10,0,10]
</pre>

<p><strong>示例 5：</strong></p>
<p><img src="./q2-e5-.png" alt=""></p>
<pre><strong>输入：</strong>root1 = [1,null,8], root2 = [8,1]
<strong>输出：</strong>[1,1,8,8]
</pre>

<p>&nbsp;</p>
<p><strong>提示：</strong></p>
<ul>
	<li>每棵树最多有&nbsp;<code>5000</code>&nbsp;个节点。</li>
	<li>每个节点的值在&nbsp;<code>[-10^5, 10^5]</code>&nbsp;之间。</li>
</ul>

---
### 思路
```

```

### 答题
``` C++
void inordered(TreeNode* root, vector<int>& out)
{
	if (root == nullptr) return;
	if (root->left != nullptr)
	{
		inordered(root->left, out);
	}
	out.push_back(root->val);
	if (root->right != nullptr)
	{
		inordered(root->right, out);
	}
}

vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
{
	vector<int> ans;
	inordered(root1, ans);
	inordered(root2, ans);
	sort(ans.begin(), ans.end());
	return ans;
}
```




