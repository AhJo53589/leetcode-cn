
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode* ans = nullptr;

        queue<pair<TreeNode *, TreeNode *>> que;
        que.push({ nullptr, root });
        while (!que.empty()) {
            for (int i = que.size(); i > 0; i--) {
                auto [p, q] = que.front();
                que.pop();

                if (q->val == x || q->val == y) {
                    if (ans != nullptr && ans != p) return true;
                    ans = p;
                }

                if (q->left != nullptr) {
                    que.push({ q, q->left });
                }
                if (q->right != nullptr) {
                    que.push({ q, q->right });
                }
            }
            if (ans != nullptr) return false;
        }
        return false;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(TreeNode* root, int x, int y)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.isCousins(root, x, y);
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
