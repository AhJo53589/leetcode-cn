


//////////////////////////////////////////////////////////////////////////
bool postOrder(TreeNode* node, int target)
{
	if (node == nullptr) return true;

	bool l = postOrder(node->left, target);
	node->left = l ? nullptr : node->left;
	bool r = postOrder(node->right, target);
	node->right = r ? nullptr : node->right;

	return (l && r && node->val == target);
}

TreeNode* removeLeafNodes(TreeNode* root, int target) 
{
	return (postOrder(root, target)) ? nullptr : root;
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
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/delete-leaves-with-a-given-value/tests.txt";
}

