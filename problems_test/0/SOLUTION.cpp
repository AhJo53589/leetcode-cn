
//////////////////////////////////////////////////////////////////////////
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
	BSTIterator(TreeNode* root) {
		if (root != nullptr) stk.push(root);
		while (!stk.empty() && stk.top()->left != nullptr) stk.push(stk.top()->left);
	}

	/** @return the next smallest number */
	int next() {
		TreeNode* pNode = stk.top();
		stk.pop();
		int res = pNode->val;
		if (pNode->right != nullptr)
		{
			stk.push(pNode->right);
			while (stk.top()->left != nullptr) stk.push(stk.top()->left);
		}
		return res;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !stk.empty();
	}

private:
	stack<TreeNode*> stk;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

//////////////////////////////////////////////////////////////////////////
//int _solution_run(int)
//{
//}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{
	vector<string> sf = tc.get<vector<string>>();
	vector<string> sp = tc.get<vector<string>>();
	vector<string> ans;

	BSTIterator *obj = nullptr;
	for (auto i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "BSTIterator")
		{
			TestCases stc(sp[i]);
			TreeNode* root = stc.get<TreeNode*>();
			obj = new BSTIterator(root);
			ans.push_back("null");
		}
		else if (sf[i] == "next")
		{
			TestCases stc(sp[i]);
			int r = obj->next();
			ans.push_back(convert<string>(r));
		}
		else if (sf[i] == "hasNext")
		{
			TestCases stc(sp[i]);
			bool r = obj->hasNext();
			ans.push_back(convert<string>(r));
		}
	}
	delete obj;

	return convert<string>(ans);
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
