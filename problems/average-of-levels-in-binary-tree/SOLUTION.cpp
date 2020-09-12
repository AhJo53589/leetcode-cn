
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> que;
        if (root != nullptr) {
            que.push(root);
        }

        while (!que.empty()) {
            int cnt = 0;
            double avg = 0;
            for (int len = que.size(); len > 0; len--) {
                auto q = que.front();
                que.pop();

                avg += q->val;
                cnt++;
                if (q->left != nullptr) {
                    que.push(q->left);
                }
                if (q->right != nullptr) {
                    que.push(q->right);
                }
            }
            ans.push_back(avg / (double)cnt);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<double> _solution_run(TreeNode* root)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.averageOfLevels(root);
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
