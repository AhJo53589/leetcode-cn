
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
    TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int start, int end) 
    {
        if (start > end) return nullptr;

        TreeNode* root = nullptr;
        int mid = start + (end - start) / 2;
        root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTHelper(nums, start, mid - 1);
        root->right = sortedArrayToBSTHelper(nums, mid + 1, end);
        return root;
    }

    void inorderTraversal(TreeNode* root, vector<int>& nums)
    {
        if (root == nullptr) return;
        inorderTraversal(root->left, nums);
        nums.push_back(root->val);
        inorderTraversal(root->right, nums);
    }

    TreeNode* balanceBST(TreeNode* root)
    {
        vector<int> nums;
        inorderTraversal(root, nums);
        TreeNode* node = sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
        return node;
    }
};

//////////////////////////////////////////////////////////////////////////
TreeNode* _solution_run(TreeNode* root)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.balanceBST(root);
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
