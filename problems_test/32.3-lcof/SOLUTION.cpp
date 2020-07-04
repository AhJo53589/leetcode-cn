
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};

        vector<vector<int>> ans;
        stack<TreeNode*> st;
        st.push(root);
        printVal(st, 0, ans);

        return ans;
    }

    void printVal(stack<TreeNode*> st, int lv, vector<vector<int>>& ans) {
        stack<TreeNode*> next;
        vector<int> temp;
        while (!st.empty()) {
            auto q = st.top();
            st.pop();

            temp.push_back(q->val);
            if (lv % 2 == 0 && q->left != nullptr) {
                next.push(q->left);
            }
            if (q->right != nullptr) {
                next.push(q->right);
            }
            if (lv % 2 == 1 && q->left != nullptr) {
                next.push(q->left);
            }
        }
        ans.push_back(temp);
        if (next.empty()) return;
        printVal(next, lv + 1, ans);
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
