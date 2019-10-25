

//////////////////////////////////////////////////////////////////////////
int maxDepth(TreeNode* root)
{
	if (root == NULL) return 0;
	return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(TreeNode* root)
{
	return maxDepth(root);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {
		"[3,9,20,null,null,15,7]",
		"3"
	};
}

//#define USE_GET_TEST_CASES_FILESTREAM
//string _get_test_cases_filestream()
//{
//	return "../../problems/maximum-depth-of-binary-tree/tests.txt";
//}

