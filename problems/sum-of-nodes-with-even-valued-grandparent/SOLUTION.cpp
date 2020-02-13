


//////////////////////////////////////////////////////////////////////////
int getChildSum(TreeNode* node)
{
	int ret = 0;
	if (node == nullptr) return ret;
	ret += (node->left != nullptr) ? node->left->val : 0;
	ret += (node->right != nullptr) ? node->right->val : 0;
	return ret;
}

void dfs(TreeNode* node, int& ans)
{
	if (node == nullptr) return;
	if (node->val % 2 == 0)
	{
		ans += getChildSum(node->left);
		ans += getChildSum(node->right);
	}
	dfs(node->left, ans);
	dfs(node->right, ans);
}

int sumEvenGrandparent(TreeNode* root) 
{
	int ans = 0;
	dfs(root, ans);
	return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(TreeNode* root)
{
	return sumEvenGrandparent(root);
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

