
//////////////////////////////////////////////////////////////////////////
//TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//	if (inorder.empty())
//		return NULL;
//	int i = inorder.size() - 1, j = postorder.size() - 1;
//	stack<TreeNode*> s;
//	TreeNode* t = new TreeNode(postorder[j]);
//	TreeNode *p = NULL;
//	s.push(t);
//	j--;
//	while (j >= 0) {
//		while (!s.empty() && inorder[i] == s.top()->val) {
//			p = s.top();
//			s.pop();
//			i--;
//		}
//		TreeNode* node = new TreeNode(postorder[j]);
//		if (p)
//			p->left = node;
//		else if (!s.empty())
//			s.top()->right = node;
//		s.push(node);
//		p = NULL;
//		j--;
//	}
//	return t;
//}

//////////////////////////////////////////////////////////////////////////
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
	if (inorder.size() != postorder.size() || inorder.size() == 0) return nullptr;

	int val = postorder[postorder.size() - 1];
	bool f = false;
	vector<int> left_inorder;
	vector<int> right_inorder;
	for (auto n : inorder)
	{
		if (n == val) { f = true; continue; }

		if (!f) left_inorder.push_back(n);
		else right_inorder.push_back(n);
	}
	vector<int> left_postorder;
	vector<int> right_postorder;
	for (auto n : postorder)
	{
		if (left_inorder.size() > left_postorder.size()) left_postorder.push_back(n);
		else if (right_inorder.size() > right_postorder.size()) right_postorder.push_back(n);
	}

	TreeNode *root = new TreeNode(val);
	root->left = buildTree(left_inorder, left_postorder);
	root->right = buildTree(right_inorder, right_postorder);
	return root;
}

//////////////////////////////////////////////////////////////////////////
TreeNode* _solution_run(vector<int>& inorder, vector<int>& postorder)
{
	return buildTree(inorder,postorder);
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
	return "..\..\problems\construct-binary-tree-from-inorder-and-postorder-traversal\tests.txt";
}

