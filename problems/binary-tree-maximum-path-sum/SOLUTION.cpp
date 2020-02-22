
//////////////////////////////////////////////////////////////////////////
int maxPathSum(TreeNode* root, int &val)
{
	if (root == nullptr) return 0;
	int left = max(0, maxPathSum(root->left, val));
	int right = max(0, maxPathSum(root->right, val));
	int lmr = root->val + left + right;
	int ret = root->val + max(left, right);
	val = max(val, max(lmr, ret));
	return ret;
}

int maxPathSum(TreeNode* root)
{
	int val = INT_MIN;
	maxPathSum(root, val);
	return val;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(TreeNode* root)
{
	return maxPathSum(root);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

