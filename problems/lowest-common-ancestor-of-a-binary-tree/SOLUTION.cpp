
//bool findOne(TreeNode *root, TreeNode *p, TreeNode *q)
//{
//	if (root == nullptr || p == nullptr || q == nullptr) return false;
//	if (root != p && root != q) return findOne(root->left, p, q) || findOne(root->right, p, q);
//	return true;
//}
//
//TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
//{
//	if (root == nullptr || p == nullptr || q == nullptr) return nullptr;
//	if (root != p && root != q)
//	{
//		bool l = findOne(root->left, p, q);
//		bool r = findOne(root->right, p, q);
//		if (l && !r) return lowestCommonAncestor(root->left, p, q);
//		if (!l && r) return lowestCommonAncestor(root->right, p, q);
//	}
//	return root;
//}

//////////////////////////////////////////////////////////////////////////
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (!root || p == root || q == root) return root;
	TreeNode *left = lowestCommonAncestor(root->left, p, q);
	if (left && left != p && left != q) return left;
	TreeNode *right = lowestCommonAncestor(root->right, p, q);
	if (left && right) return root;
	return left ? left : right;
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
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/lowest-common-ancestor-of-a-binary-tree/tests.txt";
}

