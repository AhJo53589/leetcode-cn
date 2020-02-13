


//////////////////////////////////////////////////////////////////////////
vector<int> preorderTraversal(TreeNode* root)
{
	if (root == nullptr) return {};
	vector<int> ret;
	vector<int> left;
	vector<int> right;

	ret.push_back(root->val);
	if (root->left != nullptr) left = preorderTraversal(root->left);
	ret.insert(ret.end(), left.begin(), left.end());
	if (root->right != nullptr) right = preorderTraversal(root->right);
	ret.insert(ret.end(), right.begin(), right.end());
	return ret;
}

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(TreeNode* root)
{
	return preorderTraversal(root);
}

//#define USE_SOLUTION_CUSTOM
//vector<int> _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

