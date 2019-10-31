

//////////////////////////////////////////////////////////////////////////
TreeNode* invertTree(TreeNode* root)
{
	if (root != nullptr)
	{
		swap(root->left, root->right);
		invertTree(root->left);
		invertTree(root->right);
	}
	return root;
}

//////////////////////////////////////////////////////////////////////////
TreeNode* _solution_run(TreeNode* root)
{
	return invertTree(root);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
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
	return "../../problems/invert-binary-tree/tests.txt";
}

