#define NODE_DEFINE_LEETCODE_590_N_ARY_TREE_POSTORDER_TRAVERSAL
#include "../../test/Common/Node.cpp"

//////////////////////////////////////////////////////////////////////////
//class Node {
//public:
//    int val;
//    vector<Node*> children;
//
//    Node() {}
//
//    Node(int _val) {
//        val = _val;
//    }
//
//    Node(int _val, vector<Node*> _children) {
//        val = _val;
//        children = _children;
//    }
//};

class Solution {
public:
	void postorder(Node* root, vector<int>& ans)
	{
		if (root == nullptr) return;
		for (auto c : root->children)
		{
			postorder(c, ans);
		}
		ans.push_back(root->val);
	}

    vector<int> postorder(Node* root) 
	{
		vector<int> ans;
		postorder(root, ans);
		return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
//vector<int> _solution_run(Node* root)
//{
//	//int caseNo = -1;
//	//static int caseCnt = 0;
//	//if (caseNo != -1 && caseCnt++ != caseNo) return {};
//
//	Solution sln;
//	return sln.postorder(root);
//}

#define USE_SOLUTION_CUSTOM
//Node* _solution_custom(TestCases& tc)
string _solution_custom(TestCases& tc)
{
    Node* root = StringToNode(tc.get<string>());
    cout << NodeToString(root) << endl;

    Solution sln;
    vector<int> ans = sln.postorder(root);
    return convert<string>(ans);
}


//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
