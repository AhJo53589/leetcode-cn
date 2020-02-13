
//////////////////////////////////////////////////////////////////////////
int funDelete(TreeNode **ppNode)
{
	int res = (*ppNode)->val;
	if ((*ppNode)->left == nullptr || (*ppNode)->right == nullptr)
	{
		TreeNode *pChild = ((*ppNode)->left != nullptr) ? (*ppNode)->left : (*ppNode)->right;
		delete (*ppNode);
		*ppNode = pChild;
	}
	else
	{
		TreeNode **ppChild = &((*ppNode)->left->right);
		while ((*ppChild) != nullptr && (*ppChild)->right != nullptr) ppChild = &((*ppChild)->right);

		if ((*ppChild) == nullptr)
		{
			ppChild = &((*ppNode)->right->left);
			while ((*ppChild) != nullptr && (*ppChild)->left != nullptr) ppChild = &((*ppChild)->left);
		}

		if ((*ppChild) == nullptr) ppChild = &((*ppNode)->right);

		(*ppNode)->val = funDelete(ppChild);
	}
	return res;
}

TreeNode* deleteNode(TreeNode* root, int key) //执行用时：28 ms
{
	TreeNode **ppNode = &root;
	while ((*ppNode) != nullptr)
	{
		if (key == (*ppNode)->val)
		{
			funDelete(ppNode);
			return root;
		}
		if (key < (*ppNode)->val)
		{
			ppNode = &((*ppNode)->left);
		}
		else
		{
			ppNode = &((*ppNode)->right);
		}
	}
	return root;
}

//////////////////////////////////////////////////////////////////////////
TreeNode* _solution_run(TreeNode* root, int key)
{
	return deleteNode(root,key);
}

//#define USE_SOLUTION_CUSTOM
//TreeNode* _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

