


//////////////////////////////////////////////////////////////////////////
int deepestLeavesSum(TreeNode* root) 
{
	if (root == nullptr) return 0;

	int max_level = 0;
	int ans = 0;

	queue<pair<TreeNode*, int>> que;
	que.push({ root, 0 });

	while (!que.empty())
	{
		auto q = que.front();
		que.pop();

		if (max_level != q.second)
		{
			max_level = q.second;
			ans = 0;
		}
		ans += q.first->val;

		if (q.first->left != nullptr)
		{
			que.push({ q.first->left, q.second + 1 });
		}
		if (q.first->right != nullptr)
		{
			que.push({ q.first->right, q.second + 1 });
		}
	}

	return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(TreeNode* root)
{
	return deepestLeavesSum(root);
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

