
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) return ans;
        if (root->val >= low) {
            rangeSumBST(root->left, low, high);
        }

        if (root->val >= low && root->val <= high) {
            ans += root->val;
        }

        if (root->val <= high) {
            rangeSumBST(root->right, low, high);
        }
        return ans;
    }

private:
    int ans = 0;
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(TreeNode* root, int low, int high)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << root << " , " << low << ", " << high << endl;

    Solution sln;
    return sln.rangeSumBST(root, low, high);
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
