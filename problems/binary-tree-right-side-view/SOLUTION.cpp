
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        if (root == nullptr) return {};
        vector<int> ans;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int len = que.size();
            for (int i = 0; i < len; i++) {
                auto q = que.front();
                que.pop();
                if (i == len - 1) {
                    ans.push_back(q->val);
                }
                if (q->left != nullptr) {
                    que.push(q->left);
                }
                if (q->right != nullptr) {
                    que.push(q->right);
                }
            }
        }

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(TreeNode* root)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.rightSideView(root);
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
