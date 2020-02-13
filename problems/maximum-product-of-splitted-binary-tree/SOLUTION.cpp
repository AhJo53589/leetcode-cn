


//////////////////////////////////////////////////////////////////////////
int part_sum(TreeNode* root)
{
	if (root == nullptr) return 0;
	root->val += part_sum(root->left) + part_sum(root->right);
	return root->val;
}

void getDiff(TreeNode* root, int full, int& diff)
{
	if (root == nullptr) return;
	int a = full - root->val * 2;
	diff = (abs(a) < abs(diff)) ? a : diff;
	getDiff(root->left, full, diff);
	getDiff(root->right, full, diff);
}

int maxProduct(TreeNode* root) 
{
	if (root == nullptr) return 0;
	root->val += part_sum(root->left) + part_sum(root->right);

	int full = root->val;
	int diff = INT_MAX;
	getDiff(root, full, diff);
	int half = (full + diff) / 2;

	int ans = ((long long)(full - half) * (long long)half) % (long long)(1e9 + 7);
	return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(TreeNode* root)
{
	cout << root << endl;
	return maxProduct(root);
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

