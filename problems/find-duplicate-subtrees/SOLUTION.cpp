
//////////////////////////////////////////////////////////////////////////
unordered_map<string, TreeNode *> m;
unordered_set<string> s;
vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
{
	vector<TreeNode *> treeList;
	if (root == NULL) return treeList;

	string str = TreeNodeToString(root);
	if (!m.count(str)) m[str] = root;
	else if (!s.count(str))
	{
		s.insert(str);
		treeList.push_back(root);
	}

	vector<TreeNode *> left = findDuplicateSubtrees(root->left);
	treeList.insert(treeList.end(), left.begin(), left.end());
	vector<TreeNode *> right = findDuplicateSubtrees(root->right);
	treeList.insert(treeList.end(), right.begin(), right.end());

	return treeList;
}


//////////////////////////////////////////////////////////////////////////
vector<TreeNode*> _solution_run(TreeNode* root)
{
	return findDuplicateSubtrees(root);
}

//#define USE_SOLUTION_CUSTOM
//vector<TreeNode*> _solution_custom(TestCases &tc)
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
	return "../../problems/find-duplicate-subtrees/tests.txt";
}

