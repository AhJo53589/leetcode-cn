


//////////////////////////////////////////////////////////////////////////
TreeNode* insertIntoBST(TreeNode* root, int val)
{
	TreeNode *pNode = root;
	while (pNode != nullptr)
	{
		if (val == pNode->val) return root;
		if (val < pNode->val)
		{
			if (pNode->left == nullptr) pNode->left = new TreeNode(val);
			pNode = pNode->left;
		}
		else
		{
			if (pNode->right == nullptr) pNode->right = new TreeNode(val);
			pNode = pNode->right;
		}
	}
	return root;
}


//////////////////////////////////////////////////////////////////////////
TreeNode* _solution_run(TreeNode* root, int val)
{
	return insertIntoBST(root,val);
}

//#define USE_SOLUTION_CUSTOM
//TreeNode* _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/insert-into-a-binary-search-tree/tests.txt";
}

