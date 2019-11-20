# `（中等）` [95.unique-binary-search-trees-ii 不同的二叉搜索树 II](https://leetcode-cn.com/problems/unique-binary-search-trees-ii/)

### 题目描述
<p>给定一个整数 <em>n</em>，生成所有由 1 ...&nbsp;<em>n</em> 为节点所组成的<strong>二叉搜索树</strong>。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> 3
<strong>输出:</strong>
[
&nbsp; [1,null,3,2],
&nbsp; [3,2,null,1],
&nbsp; [3,1,null,null,2],
&nbsp; [2,1,3],
&nbsp; [1,null,2,null,3]
]
<strong>解释:</strong>
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
</pre>


---
### 思路
```
标准答案。
```

### 答题
``` C++
vector<TreeNode*> bst(int begin, int back) {
	vector<TreeNode*> vs;
	if (begin > back) {
		vs.push_back(NULL);
		return vs;
	}
	for (int i = begin; i <= back; ++i) {
		vector<TreeNode*> lefts = bst(begin, i - 1);
		vector<TreeNode*> rights = bst(i + 1, back);
		for (const auto &l : lefts)
			for (const auto &r : rights) {
				TreeNode *node = new TreeNode(i);
				node->left = l;
				node->right = r;
				vs.push_back(node);
			}
	}
	return vs;
}

vector<TreeNode*> generateTrees(int n) {
	if (n == 0) return {};
	return bst(1, n);
}
```

### 其它
这个是我自己想的算法。  
一开始没想明白，树要怎么递归去接。  
所以想到有分支的时候把树复制一遍。  
应该是实现了题目要求，但是答案是错的。  
因为数字和结构的顺序跟标准答案不同。  
虽然我的算法有点蠢，但是通不过还是觉得很不爽。
``` C++
TreeNode *copyTree(TreeNode *pHead)
{
	if (pHead == NULL) return NULL;
	TreeNode *pNewHead = new TreeNode(pHead->val);
	queue<TreeNode *> q;
	queue<TreeNode *> qNew;
	q.push(pHead);
	qNew.push(pNewHead);
	while (!q.empty())
	{
		TreeNode *pNode = q.front();
		q.pop();
		TreeNode *pNodeNew = qNew.front();
		qNew.pop();
		TreeNode *pNew = NULL;
		if (pNode->left != NULL)
		{
			pNew = new TreeNode(pNode->left->val);
			pNodeNew->left = pNew;
			q.push(pNode->left);
			qNew.push(pNew);
		}
		if (pNode->right != NULL)
		{
			pNew = new TreeNode(pNode->right->val);
			pNodeNew->right = pNew;
			q.push(pNode->right);
			qNew.push(pNew);
		}
	}
	return pNewHead;
}

TreeNode *getTreeNodeByVal(TreeNode *pHead, int val)
{
	if (pHead == NULL) return NULL;
	queue<TreeNode *> q;
	q.push(pHead);
	while (!q.empty())
	{
		TreeNode *pNode = q.front();
		q.pop();
		if (pNode->val == val) return pNode;
		if (pNode->left != NULL) q.push(pNode->left);
		if (pNode->right != NULL) q.push(pNode->right);
	}
	return NULL;
}

void generateTrees(vector<TreeNode *> &trees, TreeNode *pHead, int n, int curId)
{
	if (curId == n) return;
	trees.pop_back();

	TreeNode *pNewHead = NULL;
	TreeNode *pNode = NULL;

	pNewHead = copyTree(pHead);
	trees.push_back(pNewHead);
	pNode = getTreeNodeByVal(pNewHead, curId);
	pNode->left = NULL;
	pNode->right = new TreeNode(curId + 1);
	generateTrees(trees, pNewHead, n, curId + 1);

	pNewHead = copyTree(pHead);
	trees.push_back(pNewHead);
	pNode = getTreeNodeByVal(pNewHead, curId);
	pNode->right = NULL;
	pNode->left = new TreeNode(curId + 1);
	generateTrees(trees, pNewHead, n, curId + 1);

	if (curId + 1 < n)
	{
		pNewHead = copyTree(pHead);
		trees.push_back(pNewHead);
		pNode = getTreeNodeByVal(pNewHead, curId);
		pNode->left = new TreeNode(curId + 1);
		pNode->right = new TreeNode(curId + 2);
		generateTrees(trees, pNewHead, n, curId + 2);
	}

	if (curId + 2 < n)
	{
		pNewHead = copyTree(pHead);
		trees.push_back(pNewHead);
		pNode = getTreeNodeByVal(pNewHead, curId);
		pNode->left = new TreeNode(curId + 2);
		pNode->right = new TreeNode(curId + 1);
		generateTrees(trees, pNewHead, n, curId + 2);
	}
}

vector<TreeNode*> generateTrees(int n) 
{
	vector<TreeNode *> treeList;
	TreeNode *pTree = new TreeNode(1);
	treeList.push_back(pTree);
	if (n == 1) return treeList;

	generateTrees(treeList, pTree, n, 1);

	return treeList;
}
```

