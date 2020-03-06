#define NODE_DEFINE_LEETCODE_429_N_ARY_TREE_LEVEL_ORDER_TRAVERSAL
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
    vector<vector<int>> levelOrder(Node* root) 
    {
        vector<vector<int>> ans;
        queue<Node*> queCurr;
        queue<Node*> queNext;
        queCurr.push(root);
        while (!queCurr.empty() || !queNext.empty())
        {
            vector<int> temp;
            while (!queCurr.empty())
            {
                auto q = queCurr.front();
                queCurr.pop();
                if (q == nullptr) continue;
                temp.push_back(q->val);
                for (auto c : q->children)
                {
                    queNext.push(c);
                }
            }
            if (!temp.empty())
            {
                ans.push_back(temp);
            }
            swap(queCurr, queNext);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
//vector<vector<int>> _solution_run(Node* root)
//{
//	//int caseNo = -1;
//	//static int caseCnt = 0;
//	//if (caseNo != -1 && caseCnt++ != caseNo) return {};
//
//	Solution sln;
//	return sln.levelOrder(root);
//}

#define USE_SOLUTION_CUSTOM
//Node* _solution_custom(TestCases& tc)
string _solution_custom(TestCases& tc)
{
    Node* root = StringToNode(tc.get<string>());
    cout << NodeToString(root) << endl;

    Solution sln;
    auto ans = sln.levelOrder(root);
    return convert<string>(ans);
}


//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
