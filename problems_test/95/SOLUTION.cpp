
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<TreeNode*> bst(int begin, int back) {
        vector<TreeNode*> vs;
        if (begin > back) {
            vs.push_back(NULL);
            return vs;
        }
        for (int i = begin; i <= back; ++i) {
            vector<TreeNode*> lefts = bst(begin, i - 1);
            vector<TreeNode*> rights = bst(i + 1, back);
            for (const auto& l : lefts)
                for (const auto& r : rights) {
                    TreeNode* node = new TreeNode(i);
                    node->left = l;
                    node->right = r;
                    vs.push_back(node);
                }
        }
        return vs;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return bst(1, n);
    }
};

//////////////////////////////////////////////////////////////////////////
vector<TreeNode*> _solution_run(int n)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.generateTrees(n);
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
