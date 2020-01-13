


//////////////////////////////////////////////////////////////////////////
vector<TreeNode*> dfs(int beg, int end)
{
	if (beg > end) return { nullptr };

	vector<TreeNode*> ret;
	for (int i = beg; i <= end; i++)
	{
		vector<TreeNode*> left = dfs(beg, i - 1);
		vector<TreeNode*> right = dfs(i + 1, end);
		for (auto& l : left)
		{
			for (auto& r : right)
			{
				TreeNode* node = new TreeNode(i);
				node->left = l;
				node->right = r;
				ret.push_back(node);
			}
		}
	}
	return ret;
}

int numTrees(int n) 
{
	vector<TreeNode*> ans = dfs(1, n);
	return ans.size();
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n)
{
	return numTrees(n);
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
	return "../../problems/_test_0/tests.txt";
}

