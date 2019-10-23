
void levelOrderBottom(queue<TreeNode *> que, vector<vector<int>> &ans)
{
	if (que.empty()) return;
	queue<TreeNode *> queNext;
	vector<int> vec;
	while (!que.empty())
	{
		TreeNode *pNode = que.front();
		que.pop();
		vec.push_back(pNode->val);
		if (pNode->left != nullptr) queNext.push(pNode->left);
		if (pNode->right != nullptr) queNext.push(pNode->right);
	}
	levelOrderBottom(queNext, ans);
	ans.push_back(vec);
}

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> levelOrderBottom(TreeNode* root)
{
	vector<vector<int>> ans;
	queue<TreeNode *> q;
	if (root != nullptr) q.push(root);
	levelOrderBottom(q, ans);
	return ans;
}

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(TreeNode* root)
{
	return levelOrderBottom(root);
}

//#define USE_SOLUTION_CUSTOM
//vector<vector<int>> _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {
};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/binary-tree-level-order-traversal-ii/tests.txt";
}

