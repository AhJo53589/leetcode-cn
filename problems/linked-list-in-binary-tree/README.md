# `（中等）` [5346.linked-list-in-binary-tree 二叉树中的列表](https://leetcode-cn.com/problems/linked-list-in-binary-tree/)

[contest](https://leetcode-cn.com/contest/weekly-contest-178/problems/linked-list-in-binary-tree/)

### 题目描述
<p>给你一棵以&nbsp;<code>root</code>&nbsp;为根的二叉树和一个&nbsp;<code>head</code>&nbsp;为第一个节点的链表。</p>

<p>如果在二叉树中，存在一条一直向下的路径，且每个点的数值恰好一一对应以&nbsp;<code>head</code>&nbsp;为首的链表中每个节点的值，那么请你返回 <code>True</code> ，否则返回 <code>False</code> 。</p>

<p>一直向下的路径的意思是：从树中某个节点开始，一直连续向下的路径。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/02/29/sample_1_1720.png" style="height: 280px; width: 220px;"></strong></p>

<pre><strong>输入：</strong>head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
<strong>输出：</strong>true
<strong>解释：</strong>树中蓝色的节点构成了与链表对应的子路径。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/02/29/sample_2_1720.png" style="height: 280px; width: 220px;"></strong></p>

<pre><strong>输入：</strong>head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
<strong>输出：</strong>true
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
<strong>输出：</strong>false
<strong>解释：</strong>二叉树中不存在一一对应链表的路径。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>二叉树和链表中的每个节点的值都满足&nbsp;<code>1 &lt;= node.val&nbsp;&lt;= 100</code>&nbsp;。</li>
	<li>链表包含的节点数目在&nbsp;<code>1</code>&nbsp;到&nbsp;<code>100</code>&nbsp;之间。</li>
	<li>二叉树包含的节点数目在&nbsp;<code>1</code>&nbsp;到&nbsp;<code>2500</code>&nbsp;之间。</li>
</ul>

            

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/linked-list-in-binary-tree/solution/5346-by-ikaruga/)

### 答题
``` C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool dfs(ListNode* head, TreeNode* root)
	{
		if (head == nullptr) return true;
		if (root == nullptr) return false;
		if (root->val != head->val) return false;
        return dfs(head->next, root->left) || dfs(head->next, root->right);
	}

    bool isSubPath(ListNode* head, TreeNode* root) 
	{
		queue<TreeNode*> que;
		que.push(root);

		while (!que.empty())
		{
			auto q = que.front();
			que.pop();
			if (q == nullptr) continue;

			if (q->val == head->val)
			{
				if (dfs(head, q)) return true;
			}
			que.push(q->left);
			que.push(q->right);
		}
		return false;
    }
};
```




