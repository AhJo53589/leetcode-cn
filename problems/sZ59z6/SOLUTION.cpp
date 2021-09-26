
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numColor(TreeNode* root) {
        if (root == nullptr) return ans.size();
        ans.insert(root->val);
        numColor(root->left);
        numColor(root->right);
        return ans.size();
    }

private:
    unordered_set<int> ans;
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(TreeNode* root)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.numColor(root);
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
