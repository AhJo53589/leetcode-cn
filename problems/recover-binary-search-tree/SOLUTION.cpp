
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void recoverTree(TreeNode* root) {
		inorder(root);
		swapVal(findFirst(), findLast());
    }

	void inorder(TreeNode* root) {
		if (root == nullptr) return;
		inorder(root->left);
		vt.push_back(root);
		inorder(root->right);
	}

	TreeNode* findFirst() {
		for (int i = 0; i < vt.size() - 1; i++) {
			if (vt[i]->val > vt[i + 1]->val) return vt[i];
		}
		return nullptr;
	}

	TreeNode* findLast() {
		for (int i = vt.size() - 1; i > 0; i--) {
			if (vt[i]->val < vt[i - 1]->val) return vt[i];
		}
		return nullptr;
	}

	void swapVal(TreeNode* f, TreeNode* l) {
		swap(f->val, l->val);
	}

private:
	vector<TreeNode*> vt;
};

//////////////////////////////////////////////////////////////////////////
TreeNode* _solution_run(TreeNode* root)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	sln.recoverTree(root);
	return root;
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
