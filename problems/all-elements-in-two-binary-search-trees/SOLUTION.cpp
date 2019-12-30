


//////////////////////////////////////////////////////////////////////////
void inordered(TreeNode* root, vector<int>& out)
{
	if (root == nullptr) return;
	if (root->left != nullptr)
	{
		inordered(root->left, out);
	}
	out.push_back(root->val);
	if (root->right != nullptr)
	{
		inordered(root->right, out);
	}
}

vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
{
	vector<int> ans;
	inordered(root1, ans);
	inordered(root2, ans);
	sort(ans.begin(), ans.end());
	return ans;
}

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(TreeNode* root1, TreeNode* root2)
{
	return getAllElements(root1, root2);
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
	return "../../problems/all-elements-in-two-binary-search-trees/tests.txt";
}

