
void InOrder(TreeNode *root, int &k, int &val)
{
	if (k == 0) return;
	if (root == nullptr) return;
	if (root->left != nullptr) InOrder(root->left, k, val);
	if (k-- == 1) val = root->val;
	if (root->right != nullptr) InOrder(root->right, k, val);
}


//////////////////////////////////////////////////////////////////////////
int kthSmallest(TreeNode* root, int k)
{
	int val;
	InOrder(root, k, val);
	return val;
}


//////////////////////////////////////////////////////////////////////////
int _solution_run(TreeNode* root, int k)
{
	return kthSmallest(root,k);
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
	return "../../problems/kth-smallest-element-in-a-bst/tests.txt";
}

