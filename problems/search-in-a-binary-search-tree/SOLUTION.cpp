


//////////////////////////////////////////////////////////////////////////
TreeNode* searchBST(TreeNode* root, int val) 
{
	TreeNode *pNode = root;
	while (pNode != nullptr)
	{
		if (val == pNode->val) return pNode;
		if (val < pNode->val) pNode = pNode->left;
		else pNode = pNode->right;
	}
	return nullptr;
}


//////////////////////////////////////////////////////////////////////////
TreeNode* _solution_run(TreeNode* root, int val)
{
	return searchBST(root,val);
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

