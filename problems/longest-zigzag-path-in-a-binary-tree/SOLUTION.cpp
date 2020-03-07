
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
	int longestZigZag(TreeNode* root, int left, vector<map<TreeNode*, int>>& cache)
	{
		if (root == nullptr) return 0;
        if (cache[left].count(root) != 0) return cache[left][root];
		TreeNode* pNext = (left == 0) ? root->left : root->right;
		int ret = longestZigZag(pNext, 1 - left, cache) + 1;
		cache[left][root] = ret;
		return ret;
	}

    int longestZigZag(TreeNode* root) 
	{
		int ans = 0;
		vector<map<TreeNode*, int>> cache(2, map<TreeNode*, int>());
		queue<TreeNode*> que;
		que.push(root);
		stack<TreeNode*> st;

		while (!que.empty())
		{
			auto q = que.front();
			que.pop();
			if (q == nullptr) continue;
			st.push(q);
			
			que.push(q->left);
			que.push(q->right);
		}
		while (!st.empty())
		{
			auto q = st.top();
			st.pop();

            ans = max(ans, longestZigZag(q, 0, cache));
            ans = max(ans, longestZigZag(q, 1, cache));
		}
		return ans - 1;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(TreeNode* root)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.longestZigZag(root);
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
