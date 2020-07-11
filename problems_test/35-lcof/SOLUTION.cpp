#define NODE_DEFINE_LEETCODE_138_COPY_LIST_WITH_RANDOM_POINTER
#include "../../test/Common/Node.cpp"

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/


//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> link;
        Node* pNode = head;
        while (pNode != nullptr) {
            link[pNode] = new Node(pNode->val);
            pNode = pNode->next;
        }
        pNode = head;
        while (pNode != nullptr) {
            link[pNode]->next = link[pNode->next];
            link[pNode]->random = link[pNode->random];
            pNode = pNode->next;
        }
        return link[head];
    }
};

//////////////////////////////////////////////////////////////////////////
//Node* _solution_run(Node* head)
//{
//	//int caseNo = -1;
//	//static int caseCnt = 0;
//	//if (caseNo != -1 && caseCnt++ != caseNo) return {};
//
//	Solution sln;
//	return sln.copyRandomList(head);
//}

#define USE_SOLUTION_CUSTOM
//Node* _solution_custom(TestCases& tc)
string _solution_custom(TestCases& tc)
{
    Solution sln;
    Node* root = StringToNode(tc.get<string>());
    Node* ret = sln.copyRandomList(root);
    string ans = NodeToString(ret);
    return ans;
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
