


//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* pre = nullptr;
        vector<int> ans;
        while (root != nullptr) {
            if (root->left == nullptr) {
                ans.push_back(root->val);
                root = root->right;
            }
            else {
                pre = root->left;
                while (pre->right != nullptr && pre->right != root) {
                    pre = pre->right;
                }
                if (pre->right == nullptr) {
                    pre->right = root;
                    root = root->left;
                }
                else {
                    ans.push_back(root->val);
                    pre->right = nullptr;
                    root = root->right;
                }
            }
        }
        return ans;
    }
};


//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        if (root == nullptr) return {};
        vector<int> ret;
        vector<int> left;
        vector<int> right;

        if (root->left != nullptr) left = inorderTraversal(root->left);
        ret.insert(ret.end(), left.begin(), left.end());
        ret.push_back(root->val);
        if (root->right != nullptr) right = inorderTraversal(root->right);
        ret.insert(ret.end(), right.begin(), right.end());
        return ret;
    }
};


//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(TreeNode* root)
{
    Solution sln;
	return sln.inorderTraversal(root);
}

//#define USE_SOLUTION_CUSTOM
//vector<int> _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

