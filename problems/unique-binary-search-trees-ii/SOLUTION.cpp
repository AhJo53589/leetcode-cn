
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //TreeNode *copyTree(TreeNode *pHead)
 //{
 //	if (pHead == NULL) return NULL;
 //	TreeNode *pNewHead = new TreeNode(pHead->val);
 //	queue<TreeNode *> q;
 //	queue<TreeNode *> qNew;
 //	q.push(pHead);
 //	qNew.push(pNewHead);
 //	while (!q.empty())
 //	{
 //		TreeNode *pNode = q.front();
 //		q.pop();
 //		TreeNode *pNodeNew = qNew.front();
 //		qNew.pop();
 //		TreeNode *pNew = NULL;
 //		if (pNode->left != NULL)
 //		{
 //			pNew = new TreeNode(pNode->left->val);
 //			pNodeNew->left = pNew;
 //			q.push(pNode->left);
 //			qNew.push(pNew);
 //		}
 //		if (pNode->right != NULL)
 //		{
 //			pNew = new TreeNode(pNode->right->val);
 //			pNodeNew->right = pNew;
 //			q.push(pNode->right);
 //			qNew.push(pNew);
 //		}
 //	}
 //	return pNewHead;
 //}
 //
 //TreeNode *getTreeNodeByVal(TreeNode *pHead, int val)
 //{
 //	if (pHead == NULL) return NULL;
 //	queue<TreeNode *> q;
 //	q.push(pHead);
 //	while (!q.empty())
 //	{
 //		TreeNode *pNode = q.front();
 //		q.pop();
 //		if (pNode->val == val) return pNode;
 //		if (pNode->left != NULL) q.push(pNode->left);
 //		if (pNode->right != NULL) q.push(pNode->right);
 //	}
 //	return NULL;
 //}
 //
 //void generateTrees(vector<TreeNode *> &trees, TreeNode *pHead, int n, int curId)
 //{
 //	if (curId == n) return;
 //	trees.pop_back();
 //
 //	TreeNode *pNewHead = NULL;
 //	TreeNode *pNode = NULL;
 //
 //	pNewHead = copyTree(pHead);
 //	trees.push_back(pNewHead);
 //	pNode = getTreeNodeByVal(pNewHead, curId);
 //	pNode->left = NULL;
 //	pNode->right = new TreeNode(curId + 1);
 //	generateTrees(trees, pNewHead, n, curId + 1);
 //
 //	pNewHead = copyTree(pHead);
 //	trees.push_back(pNewHead);
 //	pNode = getTreeNodeByVal(pNewHead, curId);
 //	pNode->right = NULL;
 //	pNode->left = new TreeNode(curId + 1);
 //	generateTrees(trees, pNewHead, n, curId + 1);
 //
 //	if (curId + 1 < n)
 //	{
 //		pNewHead = copyTree(pHead);
 //		trees.push_back(pNewHead);
 //		pNode = getTreeNodeByVal(pNewHead, curId);
 //		pNode->left = new TreeNode(curId + 1);
 //		pNode->right = new TreeNode(curId + 2);
 //		generateTrees(trees, pNewHead, n, curId + 2);
 //	}
 //
 //	if (curId + 2 < n)
 //	{
 //		pNewHead = copyTree(pHead);
 //		trees.push_back(pNewHead);
 //		pNode = getTreeNodeByVal(pNewHead, curId);
 //		pNode->left = new TreeNode(curId + 2);
 //		pNode->right = new TreeNode(curId + 1);
 //		generateTrees(trees, pNewHead, n, curId + 2);
 //	}
 //}
 //
 //vector<TreeNode*> generateTrees(int n) 
 //{
 //	vector<TreeNode *> treeList;
 //	TreeNode *pTree = new TreeNode(1);
 //	treeList.push_back(pTree);
 //	if (n == 1) return treeList;
 //
 //	generateTrees(treeList, pTree, n, 1);
 //
 //	return treeList;
 //}

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


//////////////////////////////////////////////////////////////////////////
vector<TreeNode*> generateTrees(int n) {
	if (n == 0) return {};
	return bst(1, n);
}


//////////////////////////////////////////////////////////////////////////
vector<TreeNode*> _solution_run(int n)
{
	return generateTrees(n);
}

//#define USE_SOLUTION_CUSTOM
//vector<TreeNode*> _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

