
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
class FindElements 
{
public:
	FindElements(TreeNode* root) 
	{
		if (root == nullptr) return;
		root->val = 0;
		s.insert(0);

		queue<TreeNode*> qt;
		qt.push(root);

		while (!qt.empty())
		{
			auto p = qt.front();
			qt.pop();

			if (p->left != nullptr)
			{
				p->left->val = p->val * 2 + 1;
				qt.push(p->left);
				s.insert(p->left->val);
			}
			if (p->right != nullptr)
			{
				p->right->val = p->val * 2 + 2;
				qt.push(p->right);
				s.insert(p->right->val);
			}
		}
	}

	bool find(int target)
	{
		return s.count(target);
	}

private:
	unordered_set<int> s;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

//////////////////////////////////////////////////////////////////////////
//string _solution_run()
//{
//}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{
	string ans = "[null";

	TreeNode *root = tc.get<TreeNode*>();
	FindElements* obj = new FindElements(root);
	vector<vector<int>> target = tc.get<vector<vector<int>>>();
	for (auto v : target)
	{
		ans += (obj->find(v[0])) ? ",true" : ",false";
	}
	ans += "]";
	return ans;
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

