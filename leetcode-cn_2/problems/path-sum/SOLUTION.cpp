


//////////////////////////////////////////////////////////////////////////
bool hasPathSum(TreeNode* root, int sum)
{
	if (!root) return false;
	if (!root->left && !root->right && root->val == sum) return true;
	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(TreeNode* root, int sum)
{
	return hasPathSum(root,sum);
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
	return "../../problems/path-sum/tests.txt";
}

