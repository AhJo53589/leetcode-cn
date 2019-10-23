
#include "..\Common\TreeNode.h"

//////////////////////////////////////////////////////////////////////////
// mirror
bool mirror(TreeNode *l, TreeNode *r)
{
	if (!l && !r) return true;
	if (!l && r) return false;
	if (l && !r) return false;
	if (l->val != r->val) return false;
	return mirror(l->left, r->right) && mirror(l->right, r->left);
}

bool isSymmetric(TreeNode* root)  // 4ms
{
	if (!root) return true;
	return mirror(root->left, root->right);
}
// end

//////////////////////////////////////////////////////////////////////////
bool _solution_run(TreeNode* root)
{
	return isSymmetric(root);
}

//#define USE_SOLUTION_CUSTOM
//bool _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {
	"[1,2,2,3,4,4,3]",
	"true",
	"[1,2,2,null,3,null,3]",
	"false"
	};
}

//#define USE_GET_TEST_CASES_FILESTREAM
//string _get_test_cases_filestream()
//{
//	return "../../problems/symmetric-tree/tests.txt";
//}

