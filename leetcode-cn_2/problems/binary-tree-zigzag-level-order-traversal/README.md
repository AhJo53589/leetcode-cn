# `（中等）` [103.binary-tree-zigzag-level-order-traversal 二叉树的锯齿形层次遍历](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/)

### 题目描述
<p>给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。</p>

<p>例如：<br>
给定二叉树&nbsp;<code>[3,9,20,null,null,15,7]</code>,</p>

<pre>    3
   / \
  9  20
    /  \
   15   7
</pre>

<p>返回锯齿形层次遍历如下：</p>

<pre>[
  [3],
  [20,9],
  [15,7]
]
</pre>


---
### 思路
```
```

### 答题
``` C++
vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
{
	if (root == nullptr) return {};
	vector<vector<int>> ans;
	stack<TreeNode *> stk[2];
	int seq = 0;
	
	stk[seq].push(root);
	while (!(stk[0].empty() && stk[1].empty()))
	{
		int seq_next = (seq + 1) % 2;
		vector<int> num;
		while (!stk[seq].empty())
		{
			TreeNode *pNode = stk[seq].top();
			stk[seq].pop();
			num.push_back(pNode->val);

			if (seq == 0)
			{
				if (pNode->left != nullptr) stk[seq_next].push(pNode->left);
				if (pNode->right != nullptr) stk[seq_next].push(pNode->right);
			}
			else
			{
				if (pNode->right != nullptr) stk[seq_next].push(pNode->right);
				if (pNode->left != nullptr) stk[seq_next].push(pNode->left);
			}
		}
		ans.push_back(num);
		seq = seq_next;
	}
	return ans;
}
```

### 其它
``` C++
```

