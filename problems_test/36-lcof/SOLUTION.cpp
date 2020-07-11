#define NODE_DEFINE_LEETCODE_426_CONVERT_BINARY_SEARCH_TREE_TO_SORTED_SORTED_DOUBLY_LINKED_LIST
#include "../../test/Common/Node.cpp"

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        auto nodes = adjNode(root);

        if (nodes.first != nullptr && nodes.second != nullptr) {
            nodes.first->left = nodes.second;
            nodes.second->right = nodes.first;
        }

        return nodes.first;
    }

    pair<Node*, Node*> adjNode(Node* root) {
        if (root == nullptr) return { nullptr, nullptr };

        auto leftNodes = adjNode(root->left);
        auto rightNodes = adjNode(root->right);

        if (root->left == nullptr) {
            leftNodes.first = root;
        }
        if (root->right == nullptr) {
            rightNodes.second = root;
        }

        if (leftNodes.second != nullptr) {
            root->left = leftNodes.second;
            leftNodes.second->right = root;
        }
        if (rightNodes.first != nullptr) {
            root->right = rightNodes.first;
            rightNodes.first->left = root;
        }

        return { leftNodes.first, rightNodes.second };
    }
};

//////////////////////////////////////////////////////////////////////////
//Node* _solution_run(Node* root)
//{
//	//int caseNo = -1;
//	//static int caseCnt = 0;
//	//if (caseNo != -1 && caseCnt++ != caseNo) return {};
//
//	Solution sln;
//	return sln.treeToDoublyList(root);
//}

#define USE_SOLUTION_CUSTOM
//Node* _solution_custom(TestCases& tc)
string _solution_custom(TestCases& tc)
{
    Solution sln;
    Node* root = StringToNode(tc.get<string>());
    Node* ret = sln.treeToDoublyList(root);
    string ans = NodeToString(ret);
    return ans;
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
