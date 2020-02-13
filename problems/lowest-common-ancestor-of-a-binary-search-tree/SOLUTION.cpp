


//////////////////////////////////////////////////////////////////////////
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if (root == nullptr || p == nullptr || q == nullptr) return nullptr;
	if (p->val > q->val) return lowestCommonAncestor(root, q, p);
	if (root->val > q->val) return lowestCommonAncestor(root->left, p, q);
	if (root->val < p->val) return lowestCommonAncestor(root->right, p, q);
	return root;
}


//////////////////////////////////////////////////////////////////////////
TreeNode* _solution_run(TreeNode* root, TreeNode* p, TreeNode* q)
{
	return lowestCommonAncestor(root,p,q);
}

#define USE_SOLUTION_CUSTOM
int _solution_custom(TestCases &tc)
{
	TreeNode* root(tc.get<TreeNode*>());
	TreeNode* p = FindTreeNode(root, tc.get<int>());
	TreeNode* q = FindTreeNode(root, tc.get<int>());
	return lowestCommonAncestor(root, p, q)->val;
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

