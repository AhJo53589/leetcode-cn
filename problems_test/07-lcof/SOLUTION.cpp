
//////////////////////////////////////////////////////////////////////////
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
    TreeNode* build(vector<int>::iterator l1, vector<int>::iterator r1, vector<int>::iterator l2, vector<int>::iterator r2) {
        TreeNode* rt = NULL;
        if (l1 != r1) {
            rt = new TreeNode(*l1);
            vector<int>::iterator mid2 = find(l2, r2, *l1);
            vector<int>::iterator mid1 = mid2 - l2 + l1;
            rt->left = build(l1 + 1, mid1 + 1, l2, mid2);
            rt->right = build(mid1 + 1, r1, mid2 + 1, r2);
        }
        return rt;
    }
};

//////////////////////////////////////////////////////////////////////////
TreeNode* _solution_run(vector<int>& preorder, vector<int>& inorder)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.buildTree(preorder, inorder);
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
