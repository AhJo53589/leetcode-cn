
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> st[2];
        if (root != nullptr) {
            st[0].push(root);
        }

        vector<vector<int>> ans;
        int i = 0;
        int j = 1;
        while (!st[0].empty() || !st[1].empty()) {
            vector<int> lv;
            while (!st[i].empty()) {
                auto node = st[i].top();
                st[i].pop();

                lv.push_back(node->val);

                if (node->left != nullptr && i == 0) {
                    st[j].push(node->left);
                }
                if (node->right != nullptr) {
                    st[j].push(node->right);
                }
                if (node->left != nullptr && i == 1) {
                    st[j].push(node->left);                    
                }          
            }
            ans.emplace_back(lv);
            swap(i, j);
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
	return sln.zigzagLevelOrder(root);
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
