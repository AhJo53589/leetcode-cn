//////////////////////////////////////////////////////////////////////////
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        m_k = k;
        for (auto& n : nums) {
            add(n);
        }
    }

    int add(int val) {
        if (pq.size() == m_k && pq.top() < val) {
            pq.pop();
        }
        if (pq.size() < m_k || pq.top() < val) {
            pq.push(val);
        }
        return pq.top();
    }

private:
    priority_queue<int, vector<int>, greater<>> pq;
    int m_k;
};


//////////////////////////////////////////////////////////////////////////
//class KthLargest {
//public:
//	KthLargest(int k, vector<int>& nums) {
//		kth = k;
//		buildTree(nums);
//	}
//
//	~KthLargest() { deleteTree(&m_pRoot); }
//
//	int add(int val) {
//		addWithoutFind(val);
//		return (kth_val >= val) ? kth_val : findKth();
//	}
//
//private:
//	int findKth()
//	{
//		vector<int> n = inorderTraversal(m_pRoot, kth);
//		kth_val = (kth <= n.size()) ? n[kth - 1] : 0;
//		return kth_val;
//	}
//
//	void addWithoutFind(int val)
//	{
//		TreeNode **ppNode = &m_pRoot;
//		while ((*ppNode) != nullptr)
//		{
//			if (val >= (*ppNode)->val) ppNode = &((*ppNode)->left);
//			else ppNode = &((*ppNode)->right);
//		}
//		(*ppNode) = new TreeNode(val);
//	}
//
//	vector<int> inorderTraversal(TreeNode* root, int k)
//	{
//		if (root == nullptr) return {};
//		vector<int> ret;
//		vector<int> left;
//		vector<int> right;
//
//		if (root->left != nullptr) left = inorderTraversal(root->left, k);
//		ret.insert(ret.end(), left.begin(), left.end());
//		ret.push_back(root->val);
//		if (ret.size() > k) return ret;
//		if (root->right != nullptr) right = inorderTraversal(root->right, k - ret.size());
//		ret.insert(ret.end(), right.begin(), right.end());
//		return ret;
//	}
//
//	void buildTree(vector<int>& nums)
//	{
//		if (nums.empty()) return;
//		for (auto i : nums) addWithoutFind(i);
//	}
//
//	void deleteTree(TreeNode **ppNode)
//	{
//		if (ppNode == nullptr || (*ppNode) == nullptr) return;
//		deleteTree(&(*ppNode)->left);
//		deleteTree(&(*ppNode)->right);
//		delete (*ppNode);
//		*ppNode = nullptr;
//	}
//
//private:
//	TreeNode *m_pRoot;
//	int kth;
//	int kth_val;
//};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

//////////////////////////////////////////////////////////////////////////
//int _solution_run(int val)
//{
//	return add(val);
//}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{
	vector<string> sf = tc.get<vector<string>>();
	vector<string> sp = tc.get<vector<string>>();
	vector<string> ans;

	KthLargest *obj = nullptr;
	for (size_t i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "KthLargest")
		{
			TestCases stc(sp[i]);
			int k = stc.get<int>();
			vector<int> nums = stc.get<vector<int>>();
			obj = new KthLargest(k, nums);
			ans.push_back("null");
		}
		else if (sf[i] == "add")
		{
			TestCases stc(sp[i]);
			int val = stc.get<int>();
			int r = obj->add(val);
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

