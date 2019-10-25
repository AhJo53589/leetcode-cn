
//////////////////////////////////////////////////////////////////////////
int getTreeHeight(TreeNode *pNode)
{
	if (pNode == nullptr) return 0;
	int l = getTreeHeight(pNode->left);
	int r = getTreeHeight(pNode->right);
	if (l == -1 || r == -1 || abs(l - r) > 1) return -1;
	return max(l, r) + 1;
}

bool isBalanced(TreeNode* root)
{
	return getTreeHeight(root) != -1;
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(TreeNode* root)
{
	return isBalanced(root);
}

//#define USE_SOLUTION_CUSTOM
//bool _solution_custom(TestCases &tc)
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
	return "../../problems/balanced-binary-tree/tests.txt";
}

