
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) return nullptr;

        TreeNode* root = new TreeNode(0);
        root->val += (t1 != nullptr) ? t1->val : 0;
        root->val += (t2 != nullptr) ? t2->val : 0;

        root->left = mergeTrees((t1 != nullptr) ? t1->left : nullptr, (t2 != nullptr) ? t2->left : nullptr);
        root->right = mergeTrees((t1 != nullptr) ? t1->right : nullptr, (t2 != nullptr) ? t2->right : nullptr);

        return root;
    }
};

//////////////////////////////////////////////////////////////////////////
TreeNode* _solution_run(TreeNode* t1, TreeNode* t2)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.mergeTrees(t1, t2);
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
