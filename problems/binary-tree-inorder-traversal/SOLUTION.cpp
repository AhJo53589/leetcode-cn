


//////////////////////////////////////////////////////////////////////////
vector<int> inorderTraversal(TreeNode* root)
{
	if (root == nullptr) return {};
	vector<int> ret;
	vector<int> left;
	vector<int> right;

	if (root->left != nullptr) left = inorderTraversal(root->left);
	ret.insert(ret.end(), left.begin(), left.end());
	ret.push_back(root->val);
	if (root->right != nullptr) right = inorderTraversal(root->right);
	ret.insert(ret.end(), right.begin(), right.end());
	return ret;
}


//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(TreeNode* root)
{
	return inorderTraversal(root);
}

//#define USE_SOLUTION_CUSTOM
//vector<int> _solution_custom(TestCases &tc)
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
	return "../../problems/binary-tree-inorder-traversal/tests.txt";
}

