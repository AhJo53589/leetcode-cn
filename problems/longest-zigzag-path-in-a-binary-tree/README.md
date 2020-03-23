# `（中等）` [1372.longest-zigzag-path-in-a-binary-tree 二叉树中的最长交错路径](https://leetcode-cn.com/problems/longest-zigzag-path-in-a-binary-tree/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-21/problems/longest-zigzag-path-in-a-binary-tree/)

### 题目描述
<p>给你一棵以&nbsp;<code>root</code>&nbsp;为根的二叉树，二叉树中的交错路径定义如下：</p>

<ul>
	<li>选择二叉树中 <strong>任意</strong>&nbsp;节点和一个方向（左或者右）。</li>
	<li>如果前进方向为右，那么移动到当前节点的的右子节点，否则移动到它的左子节点。</li>
	<li>改变前进方向：左变右或者右变左。</li>
	<li>重复第二步和第三步，直到你在树中无法继续移动。</li>
</ul>

<p>交错路径的长度定义为：<strong>访问过的节点数目 - 1</strong>（单个节点的路径长度为 0 ）。</p>

<p>请你返回给定树中最长 <strong>交错路径</strong>&nbsp;的长度。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/03/07/sample_1_1702.png" style="height: 283px; width: 151px;"></strong></p>

<pre><strong>输入：</strong>root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]
<strong>输出：</strong>3
<strong>解释：</strong>蓝色节点为树中最长交错路径（右 -&gt; 左 -&gt; 右）。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/03/07/sample_2_1702.png" style="height: 253px; width: 120px;"></strong></p>

<pre><strong>输入：</strong>root = [1,1,1,null,1,null,null,1,1,null,1]
<strong>输出：</strong>4
<strong>解释：</strong>蓝色节点为树中最长交错路径（左 -&gt; 右 -&gt; 左 -&gt; 右）。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>root = [1]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>每棵树最多有&nbsp;<code>50000</code>&nbsp;个节点。</li>
	<li>每个节点的值在&nbsp;<code>[1, 100]</code> 之间。</li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
	int longestZigZag(TreeNode* root, int left, vector<map<TreeNode*, int>>& cache)
	{
		if (root == nullptr) return 0;
        if (cache[left].count(root) != 0) return cache[left][root];
		TreeNode* pNext = (left == 0) ? root->left : root->right;
		int ret = longestZigZag(pNext, 1 - left, cache) + 1;
		cache[left][root] = ret;
		return ret;
	}

    int longestZigZag(TreeNode* root) 
	{
		int ans = 0;
		vector<map<TreeNode*, int>> cache(2, map<TreeNode*, int>());
		queue<TreeNode*> que;
		que.push(root);
		stack<TreeNode*> st;

		while (!que.empty())
		{
			auto q = que.front();
			que.pop();
			if (q == nullptr) continue;
			st.push(q);
			
			que.push(q->left);
			que.push(q->right);
		}
		while (!st.empty())
		{
			auto q = st.top();
			st.pop();

            ans = max(ans, longestZigZag(q, 0, cache));
            ans = max(ans, longestZigZag(q, 1, cache));
		}
		return ans - 1;
    }
};
```




