

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> levelOrder(TreeNode* root)
{
	if (root == nullptr) return {};
	vector<vector<int>> ans;
	queue<TreeNode *> que[2];
	int seq = 0;

	que[seq].push(root);
	while (!(que[0].empty() && que[1].empty()))
	{
		int seq_next = (seq + 1) % 2;
		vector<int> num;
		while (!que[seq].empty())
		{
			TreeNode *pNode = que[seq].front();
			que[seq].pop();
			num.push_back(pNode->val);

			if (pNode->left != nullptr) que[seq_next].push(pNode->left);
			if (pNode->right != nullptr) que[seq_next].push(pNode->right);
		}
		ans.push_back(num);
		seq = seq_next;
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(TreeNode* root)
{
	return levelOrder(root);
}

//#define USE_SOLUTION_CUSTOM
//vector<vector<int>> _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {
		"[3,9,20,null,null,15,7]",
		"[[3],[9,20],[15,7]]"
	};
}

//#define USE_GET_TEST_CASES_FILESTREAM
//string _get_test_cases_filestream()
//{
//	return "../../problems/binary-tree-level-order-traversal/tests.txt";
//}

