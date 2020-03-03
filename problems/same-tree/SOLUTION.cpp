
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
	{
		if (p == nullptr && q == nullptr) return true;
		if (p == nullptr && q != nullptr) return false;
		if (p != nullptr && q == nullptr) return false;
		if (p->val != q->val) return false;
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(TreeNode* p, TreeNode* q)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.isSameTree(p, q);
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
