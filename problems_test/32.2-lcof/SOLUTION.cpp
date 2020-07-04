
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};

        vector<vector<int>> ans;

        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            vector<int> temp;

            for (int i = que.size(); i > 0; i--) {
                auto q = que.front();
                que.pop();

                temp.push_back(q->val);

                if (q->left != nullptr) {
                    que.push(q->left);
                }
                if (q->right != nullptr) {
                    que.push(q->right);
                }
            }

            ans.push_back(temp);
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
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
