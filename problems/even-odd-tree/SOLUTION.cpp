
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        
        bool flag = false;
        while (!que.empty()) {
            flag = !flag;
            int val = flag ? 0 : INT_MAX;
            for (int len = que.size(); len > 0; len--) {
                auto q = que.front();
                que.pop();
                if (q == nullptr) continue;
                
                if (flag && (q->val % 2 == 0 || q->val <= val)) return false;
                if (!flag && (q->val % 2 == 1 || q->val >= val)) return false;
                val = q->val;
                
                que.push(q->left);
                que.push(q->right);
            }
        }
        return true;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(TreeNode* root)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.isEvenOddTree(root);
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
