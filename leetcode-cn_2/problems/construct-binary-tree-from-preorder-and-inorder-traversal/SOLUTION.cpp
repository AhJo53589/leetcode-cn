

//////////////////////////////////////////////////////////////////////////
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
	if (preorder.size() != inorder.size() || inorder.size() == 0) return nullptr;

	int val = preorder[0];
	bool f = false;
	vector<int> left_inorder;
	vector<int> right_inorder;
	for (auto n : inorder)
	{
		if (n == val) { f = true; continue; }

		if (!f) left_inorder.push_back(n);
		else right_inorder.push_back(n);
	}
	vector<int> left_preorder;
	vector<int> right_preorder;
	for (auto n : preorder)
	{
		if (n == val) continue;
		if (left_inorder.size() > left_preorder.size()) left_preorder.push_back(n);
		else if (right_inorder.size() > right_preorder.size()) right_preorder.push_back(n);
	}

	TreeNode *root = new TreeNode(val);
	root->left = buildTree(left_preorder, left_inorder);
	root->right = buildTree(right_preorder, right_inorder);
	return root;
}


//////////////////////////////////////////////////////////////////////////
TreeNode* _solution_run(vector<int>& preorder, vector<int>& inorder)
{
	return buildTree(preorder,inorder);
}

//#define USE_SOLUTION_CUSTOM
//TreeNode* _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {
	};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/construct-binary-tree-from-preorder-and-inorder-traversal/tests.txt";
}

