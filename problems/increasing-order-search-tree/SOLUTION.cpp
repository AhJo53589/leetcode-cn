
//////////////////////////////////////////////////////////////////////////
class Solution {
private:
    TreeNode *resNode;

public:
    void inorder(TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left);

        // 在中序遍历的过程中修改节点指向
        resNode->right = node;
        node->left = nullptr;
        resNode = node;

        inorder(node->right);
    }

    TreeNode *increasingBST(TreeNode *root) {
        TreeNode *dummyNode = new TreeNode(-1);
        resNode = dummyNode;
        inorder(root);
        return dummyNode->right;
    }
};

//////////////////////////////////////////////////////////////////////////
TreeNode* _solution_run(TreeNode* root)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.increasingBST(root);
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
