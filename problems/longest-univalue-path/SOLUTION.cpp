
int help(TreeNode* node, int &ans)
{
    if (node == nullptr) return 0;

    int l = help(node->left, ans);
    int r = help(node->right, ans);

    int samel = 0;
    int samer = 0;
    if (node->left != nullptr && node->val == node->left->val)
    {
        samel = l + 1;
    }
    if (node->right != nullptr && node->val == node->right->val)
    {
        samer = r + 1;
    }
    ans = max(ans, samel + samer);
    return max(samel, samer);
}

//////////////////////////////////////////////////////////////////////////
int longestUnivaluePath(TreeNode* root)
{

    int ans = 0;
    help(root, ans);
    return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(TreeNode* root)
{
	return longestUnivaluePath(root);
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
	return "../../problems/longest-univalue-path/tests.txt";
}

