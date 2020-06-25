
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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr) return false;

        queue<TreeNode*> que;
        que.push(A);
        while (!que.empty()) {
            auto q = que.front();
            que.pop();

            if (q->val == B->val) {
                if (isSub(q, B)) return true;
            }
            if (q->left != nullptr) {
                que.push(q->left);
            }
            if (q->right != nullptr) {
                que.push(q->right);
            }
        }

        return false;
    }

    bool isSub(TreeNode* A, TreeNode* B) {
        if (B == nullptr) return true;
        if (A == nullptr) return false;
        if (A->val != B->val) return false;
        return isSub(A->left, B->left) && isSub(A->right, B->right);
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(TreeNode* A, TreeNode* B)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.isSubStructure(A, B);
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
