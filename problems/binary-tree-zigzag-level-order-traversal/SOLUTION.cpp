

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
	if (root == nullptr) return {};
	vector<vector<int>> ans;
	stack<TreeNode *> stk[2];
	int seq = 0;

	stk[seq].push(root);
	while (!(stk[0].empty() && stk[1].empty()))
	{
		int seq_next = (seq + 1) % 2;
		vector<int> num;
		while (!stk[seq].empty())
		{
			TreeNode *pNode = stk[seq].top();
			stk[seq].pop();
			num.push_back(pNode->val);

			if (seq == 0)
			{
				if (pNode->left != nullptr) stk[seq_next].push(pNode->left);
				if (pNode->right != nullptr) stk[seq_next].push(pNode->right);
			}
			else
			{
				if (pNode->right != nullptr) stk[seq_next].push(pNode->right);
				if (pNode->left != nullptr) stk[seq_next].push(pNode->left);
			}
		}
		ans.push_back(num);
		seq = seq_next;
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(TreeNode* root)
{
	return zigzagLevelOrder(root);
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
	"[[3],[20,9],[15,7]]"
	};
}

//#define USE_GET_TEST_CASES_FILESTREAM
//string _get_test_cases_filestream()
//{
//	return "../../problems/binary-tree-zigzag-level-order-traversal/tests.txt";
//}

