
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        inordered(root);
        return ans;
    }

    void inordered(TreeNode* root) {
        if (root == nullptr) return;
        inordered(root->left);
        if (val != -1) {
            ans = min(ans, root->val - val);
        }
        val = root->val;
        inordered(root->right);
    }

private:
    int ans = INT_MAX;
    int val = -1;
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(TreeNode* root)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.getMinimumDifference(root);
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
