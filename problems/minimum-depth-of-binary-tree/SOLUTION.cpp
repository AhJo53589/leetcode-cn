


//////////////////////////////////////////////////////////////////////////
int minDepth(TreeNode* root)
{
	if (root == nullptr) return 0;
	if (root->left == nullptr && root->right == nullptr) return 1;
	int left = (root->left == nullptr) ? INT_MAX : minDepth(root->left);
	int right = (root->right == nullptr) ? INT_MAX : minDepth(root->right);
	return min(left, right) + 1;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(TreeNode* root)
{
	return minDepth(root);
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

