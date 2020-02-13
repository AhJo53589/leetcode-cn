
//////////////////////////////////////////////////////////////////////////
void binaryTreePaths(TreeNode* root, string path, vector<string> &vec)
{
	path = path.empty() ? to_string(root->val) : path + "->" + to_string(root->val);
	if (root->left != nullptr)
	{
		binaryTreePaths(root->left, path, vec);
	}
	if (root->right != nullptr)
	{
		binaryTreePaths(root->right, path, vec);
	}
	if (root->left == nullptr && root->right == nullptr)
	{
		vec.push_back(path);
	}
}

vector<string> binaryTreePaths(TreeNode* root)
{
	if (root == nullptr) return {};
	string path;
	vector<string> vec;
	binaryTreePaths(root, path, vec);
	return vec;
}

//////////////////////////////////////////////////////////////////////////
vector<string> _solution_run(TreeNode* root)
{
	return binaryTreePaths(root);
}

//#define USE_SOLUTION_CUSTOM
//vector<string> _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

