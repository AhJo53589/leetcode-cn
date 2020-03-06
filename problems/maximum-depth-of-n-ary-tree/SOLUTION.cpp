#define NODE_DEFINE_LEETCODE_559_MAXIMUM_DEPTH_OF_N_ARY_TREE
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
    int maxDepth(Node* root) 
    {
        if (root == nullptr) return 0;
        int ans = 0;
        queue<Node*> que;
        que.push(root);

        while (!que.empty())
        {
            int len = que.size();
            while (len-- > 0)
            {
                auto q = que.front();
                que.pop();
                if (q == nullptr) continue;
                
                for (auto& c : q->children)
                {
                    que.push(c);
                }
            }
            ans++;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
//int _solution_run(Node* root)
//{
//	//int caseNo = -1;
//	//static int caseCnt = 0;
//	//if (caseNo != -1 && caseCnt++ != caseNo) return {};
//
//	Solution sln;
//	return sln.maxDepth(root);
//}

#define USE_SOLUTION_CUSTOM
//Node* _solution_custom(TestCases& tc)
string _solution_custom(TestCases& tc)
{
    Node* root = StringToNode(tc.get<string>());
    cout << NodeToString(root) << endl;

    Solution sln;
    auto ans = sln.maxDepth(root);
    return convert<string>(ans);
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
