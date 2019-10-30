# `（中等）` [337.house-robber-iii 打家劫舍 III](https://leetcode-cn.com/problems/house-robber-iii/)

### 题目描述
<p>在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。</p>

<p>计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入: </strong>[3,2,3,null,3,null,1]

     <strong>3</strong>
    / \
   2   3
    \   \ 
     <strong>3</strong>   <strong>1</strong>

<strong>输出:</strong> 7 
<strong>解释:</strong>&nbsp;小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = <strong>7</strong>.</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入: </strong>[3,4,5,1,3,null,1]

&nbsp;    3
    / \
   <strong>4</strong>   <strong>5</strong>
  / \   \ 
 1   3   1

<strong>输出:</strong> 9
<strong>解释:</strong>&nbsp;小偷一晚能够盗取的最高金额&nbsp;= <strong>4</strong> + <strong>5</strong> = <strong>9</strong>.
</pre>


---
### 思路
```
使用后序遍历，从后往前对每个结点计算。  
使用两个值来记录sum，  
一个是明值（包含自己的值，以及所有子结点的暗值的和。代码中index = 0）
一个是暗值（不包含自己的值，包含所有子结点的最优解。代码中index = 1）
通过计算，最后如果明值没有暗值大，那么将更新成暗值的值（更新成最优解）
```

[发布的题解](https://leetcode-cn.com/problems/house-robber-iii/solution/da-jia-jie-she-iii-dai-ma-jian-ji-yi-dong-iii-by-i/)

### 答题
``` C++
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
void PostOrder(TreeNode *root, vector<TreeNode *>&pNodeList)
{
	if (root == NULL) return;
	if (root->left != NULL) PostOrder(root->left, pNodeList);
	if (root->right != NULL) PostOrder(root->right, pNodeList);
	pNodeList.push_back(root);
}

unordered_map<TreeNode *, int> robMemo[2];
int rob(TreeNode* pNode)
{
	if (pNode == NULL) return 0;
	vector<TreeNode *> pNodeList;
	PostOrder(pNode, pNodeList);

	for (auto p : pNodeList)
	{
		int s[2] = { 0,0 };	// 0 == include node val, 1 == not include node val

		s[0] = p->val;
		if (p->left != NULL) s[0] += robMemo[1][p->left];
		if (p->right != NULL) s[0] += robMemo[1][p->right];

		if (p->left != NULL) s[1] += robMemo[0][p->left];
		if (p->right != NULL) s[1] += robMemo[0][p->right];

		s[0] = max(s[0], s[1]);	// copy best val

		robMemo[0][p] = s[0];
		robMemo[1][p] = s[1];
	}
	return robMemo[0][pNode];
}
};
```

### 其它
先用的暴力递归法，加了cache才勉强合格。
考虑最小的二叉树，3个元素。
那么要么选根结点，要么选两个子结点。
所以思路为，  
rob 根结点 + 子结点的子结点 和 rob 左右子结点 取最大值。
``` C++
vector<TreeNode *>getAllChild(vector<TreeNode *>pNode)
{
	vector<TreeNode *> pChild;
	if (pNode.empty()) return pChild;
	for (auto p : pNode)
	{
		if (p == NULL) continue;
		if (p->left != NULL) pChild.push_back(p->left);
		if (p->right != NULL) pChild.push_back(p->right);
	}
	return pChild;
}

unordered_map<TreeNode *, int> robMemo;
int rob(TreeNode* pNode)
{
	if (pNode == NULL) return 0;
	if (robMemo.count(pNode)) return robMemo[pNode];
	int sum = 0;

	// rob this house and prepare rob "child-child" houses
	sum = pNode->val;
	vector<TreeNode *> pChild = getAllChild({ pNode });
	pChild = getAllChild({ pChild });
	for (auto p : pChild) sum += rob(p);

	// rob "child" houses
	sum = max(sum, rob(pNode->left) + rob(pNode->right));

	// Memo
	robMemo[pNode] = sum;
	return sum;
}
```

