
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxSumBST(TreeNode* root, map<TreeNode*, int>& cache)
    {
        if (root == nullptr) return 0;
        if (cache.count(root) != 0) return cache[root];

        int ans = root->val;
        bool flag = true;
        if (root->left != nullptr && root->left->val >= root->val)
        {
            flag = false;
        }
        int left = maxSumBST(root->left, cache);
        if (left == INT_MIN)
        {
            flag = false;
        }
        else
        {
            ans += left;
        }

        if (root->right != nullptr && root->right->val <= root->val)
        {
            flag = false;
        }
        int right = maxSumBST(root->right, cache);
        if (right == INT_MIN)
        {
            flag = false;
        }
        else
        {
            ans += right;
        }

        ans = flag ? ans : INT_MIN;
        cache[root] = ans;
        return ans;
    }

    int maxSumBST(TreeNode* root) 
    {
        int ans = 0;
        map<TreeNode*, int> cache;
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

            ans = max(ans, maxSumBST(q, cache));
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(TreeNode* root)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.maxSumBST(root);
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
