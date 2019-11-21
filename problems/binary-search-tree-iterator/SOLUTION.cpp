
//////////////////////////////////////////////////////////////////////////
class BSTIterator {
public:
	BSTIterator(TreeNode* root) {
		if (root != nullptr) stk.push(root);
		while (!stk.empty() && stk.top()->left != nullptr) stk.push(stk.top()->left);
	}

	/** @return the next smallest number */
	int next() {
		TreeNode *pNode = stk.top();
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
	stack<TreeNode *> stk;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

//////////////////////////////////////////////////////////////////////////
//int _solution_run(int a)
//{
//	return next(a);
//}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{
	vector<string> sf = tc.get<vector<string>>();
	string param = tc.get<string>();

	string ans = "[";
	BSTIterator *obj = nullptr;
	for (size_t i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "BSTIterator")
		{
			TreeNode *pRoot = StringToTreeNode(param);
			obj = new BSTIterator(pRoot);
			ans += "null";
		}
		else if (sf[i] == "next")
		{
			int r = obj->next();
			ans += to_string(r);
		}
		else if (sf[i] == "hasNext")
		{
			bool r = obj->hasNext();
			ans += r ? "true" : "false";
		}
		ans += ",";
	}
	ans.pop_back();
	ans += "]";
	return ans;
}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/binary-search-tree-iterator/tests.txt";
}

