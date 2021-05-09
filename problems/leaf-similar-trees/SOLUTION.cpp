
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1;
        vector<int> leaf2;
        inorder(root1, leaf1);
        inorder(root2, leaf2);
        return (leaf1 == leaf2);
    }

    void inorder(TreeNode* root, vector<int>& leaf) {
        if (root == nullptr) return;
        if (root->left != nullptr) {
            inorder(root->left, leaf);
        }
        if (root->right != nullptr) {
            inorder(root->right, leaf);
        }
        if (root->left == nullptr && root->right == nullptr) {
            leaf.push_back(root->val);
        }
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(TreeNode* root1, TreeNode* root2)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.leafSimilar(root1, root2);
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
