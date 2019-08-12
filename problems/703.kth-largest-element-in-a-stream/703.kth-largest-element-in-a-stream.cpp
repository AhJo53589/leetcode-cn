// 703.kth-largest-element-in-a-stream.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <list>
#include <string>
#include <random>
#include <bitset>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;


//////////////////////////////////////////////////////////////////////////
//class KthLargest {
//public:
//	priority_queue<int, vector<int>, greater<int>> pq; //最小堆
//	int K;
//	KthLargest(int k, vector<int>& nums) {
//		K = k;
//		for (int& nu : nums) {
//			this->add(nu);
//		}
//	}
//
//	int add(int val) {
//		if (pq.size() < K)
//			pq.push(val);
//		else if (pq.top() < val) {  //val大于堆顶，入堆
//			pq.pop();
//			pq.push(val);
//		}
//		return pq.top();  //否则直接返回堆顶
//	}
//};

//////////////////////////////////////////////////////////////////////////
class KthLargest {
public:
	KthLargest(int k, vector<int>& nums) {
		m_k = k;
		m_nums = nums;
		sort(m_nums.rbegin(), m_nums.rend());
	}

	int add(int val) {
		if (m_nums.size() != m_k || val > m_nums.back())
		{
			m_nums.push_back(val);
			int i = m_nums.size() - 2;
			for (; i >= 0; i--)
			{
				if (m_nums[i] < val) m_nums[i + 1] = m_nums[i];
				else break;
			}
			m_nums[i + 1] = val;
		}
		while (m_nums.size() > m_k) m_nums.pop_back();
		return (m_k > m_nums.size()) ? 0 : m_nums.back();
	}

private:
	vector<int> m_nums;
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


int main()
{
	vector<vector<int>> N;
	vector<vector<int>> ADD;
	vector<int> K;
	vector<vector<int>> A;

	N.push_back({ 4,5,8,2 });
	K.push_back(3);
	ADD.push_back({ 3,5,10,9,4 });
	A.push_back({ 4,5,5,8,8 });

	N.push_back({  });
	K.push_back(1);
	ADD.push_back({ -3,-2,-4,0,4 });
	A.push_back({ -3,-2,-2,0,4 });

	for (int i = 0; i < N.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		KthLargest* obj = new KthLargest(K[i], N[i]);
		for (int j = 0; j < ADD[i].size(); j++)
		{
			int ans = obj->add(ADD[i][j]);
			string check = (ans == A[i][j]) ? "" : "\t\tWRONG!";
			cout << ans << "\t <== " << A[i][j] << check << endl;
		}

		delete obj;
	}
}