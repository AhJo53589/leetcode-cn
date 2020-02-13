
//vector<TreeNode *>getAllChild(vector<TreeNode *>pNode)
//{
//	vector<TreeNode *> pChild;
//	if (pNode.empty()) return pChild;
//	for (auto p : pNode)
//	{
//		if (p == NULL) continue;
//		if (p->left != NULL) pChild.push_back(p->left);
//		if (p->right != NULL) pChild.push_back(p->right);
//	}
//	return pChild;
//}
//
//unordered_map<TreeNode *, int> robMemo;
//int rob(TreeNode* pNode)
//{
//	if (pNode == NULL) return 0;
//	if (robMemo.count(pNode)) return robMemo[pNode];
//	int sum = 0;
//
//	// rob this house and prepare rob "child-child" houses
//	sum = pNode->val;
//	vector<TreeNode *> pChild = getAllChild({ pNode });
//	pChild = getAllChild({ pChild });
//	for (auto p : pChild) sum += rob(p);
//
//	// rob "child" houses
//	sum = max(sum, rob(pNode->left) + rob(pNode->right));
//
//	// Memo
//	robMemo[pNode] = sum;
//	return sum;
//}


//////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////////
int _solution_run(TreeNode* pNode)
{
	return rob(pNode);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

