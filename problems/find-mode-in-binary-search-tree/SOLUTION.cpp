
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }

    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->left);
        cnt = (root->val == val) ? cnt + 1 : 1;
        if (cnt == maxcnt) {
            ans.push_back(root->val);
        }
        else if (cnt > maxcnt) {
            maxcnt = cnt;
            ans = vector<int>(1, root->val);
        }
        val = root->val;
        inorder(root->right);
    }

private:
    int val = INT_MIN;
    int cnt = 0;
    int maxcnt = 0;
    vector<int> ans;
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(TreeNode* root)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.findMode(root);
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
