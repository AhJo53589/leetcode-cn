


//////////////////////////////////////////////////////////////////////////
TreeNode* removeLeafNodes(TreeNode* root, int target) 
{
	if (root == nullptr) return nullptr;

	root->left = removeLeafNodes(root->left, target);
	root->right = removeLeafNodes(root->right, target);

	return (root->left == nullptr && root->right == nullptr && root->val == target) ? nullptr : root;
}

//////////////////////////////////////////////////////////////////////////
TreeNode* _solution_run(TreeNode* root, int target)
{
	return removeLeafNodes(root,target);
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

