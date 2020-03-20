
class Solution2 {
public:
    void flatten(TreeNode* root)
    {
        if (root == nullptr) return;
        flatten(root->left);
        flatten(root->right);

        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = nullptr;
        while (root->right != nullptr) 
        {
            root = root->right;
        }
        root->right = temp;
    }
};

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void flatten(TreeNode* root) 
    {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while (curr != nullptr)
        {
            if (curr->right != nullptr)
            {
                st.push(curr->right);
                curr->right = nullptr;
            }
            if (curr->left != nullptr)
            {
                curr->right = curr->left;
                curr->left = nullptr;
            }
            if (curr->right == nullptr && !st.empty())
            {
                curr->right = st.top();
                st.pop();
            }
            curr = curr->right;
        }
    }
};

//////////////////////////////////////////////////////////////////////////
TreeNode* _solution_run(TreeNode* root)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << root << endl;
    Solution sln;
    sln.flatten(root);
    return root;
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//    return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
