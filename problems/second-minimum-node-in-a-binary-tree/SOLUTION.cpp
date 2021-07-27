
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        set<int> ans;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            auto q = que.front();
            que.pop();

            ans.insert(q->val);

            if (q->left != nullptr) {
                que.push(q->left);
            }
            if (q->right != nullptr) {
                que.push(q->right);
            }
        }

        if (ans.size() >= 2) {
            auto it = ans.begin();
            it++;
            return *it;
        }
        return -1;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(TreeNode* root)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.findSecondMinimumValue(root);
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
