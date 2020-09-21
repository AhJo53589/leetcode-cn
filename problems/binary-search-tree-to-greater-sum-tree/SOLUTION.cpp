
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        dfs(root, 0);
        return root;
    }

    int dfs(TreeNode* root, int add) {
        if (root == nullptr) return add;
        root->val += dfs(root->right, add);
        return dfs(root->left, root->val);
    }
};

//////////////////////////////////////////////////////////////////////////
TreeNode* _solution_run(TreeNode* root)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.bstToGst(root);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
