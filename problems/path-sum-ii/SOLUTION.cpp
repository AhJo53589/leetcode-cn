
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//////////////////////////////////////////////////////////////////////////
void dfs(TreeNode *pNode, int sum, vector<int> path, vector<vector<int>>& ans)
{
	if (pNode == nullptr) return;
	sum -= pNode->val;
	path.push_back(pNode->val);

	if (pNode->left == nullptr && pNode->right == nullptr)
	{
		if (sum != 0) return;
		ans.push_back(path);
		return;
	}

	dfs(pNode->left, sum, path, ans);
	dfs(pNode->right, sum, path, ans);
}

vector<vector<int>> pathSum(TreeNode* root, int sum) 
{
	vector<vector<int>> ans;
	dfs(root, sum, vector<int>(), ans);
	return ans;
}

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(TreeNode* root, int sum)
{
	return pathSum(root,sum);
}

//#define USE_SOLUTION_CUSTOM
//vector<vector<int>> _solution_custom(TestCases &tc)
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
	return "../../problems/path-sum-ii/tests.txt";
}

