
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> que[2];
        int seq = 0;

        que[seq].push(root);
        while (!(que[0].empty() && que[1].empty())) {
            int seq_next = (seq + 1) % 2;
            vector<int> num;
            while (!que[seq].empty()) {
                TreeNode* pNode = que[seq].front();
                que[seq].pop();
                num.push_back(pNode->val);

                if (pNode->left != nullptr) {
                    que[seq_next].push(pNode->left);
                }
                if (pNode->right != nullptr) {
                    que[seq_next].push(pNode->right);
                }
            }
            ans.push_back(num);
            seq = seq_next;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(TreeNode* root)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.levelOrder(root);
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
