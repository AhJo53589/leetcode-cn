/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        int start = 0;
        return preOrder(S, start, 0);
    }

    TreeNode* preOrder(string& S, int& start, int lv) {
        int nextLv = getDepth(S, start);
        if (nextLv != lv) {
            return nullptr;
        }
        start += lv;
        int val = getVal(S, start);
        TreeNode* node = new TreeNode(val);
        node->left = preOrder(S, start, lv + 1);
        node->right = preOrder(S, start, lv + 1);
        return node;
    }

    int getDepth(string& S, int start) {
        int cnt = 0;
        while (start < S.size() && S[start + cnt] == '-') {
            cnt++;
        }
        return cnt;
    }

    int getVal(string& S, int& start) {
        int val = 0;
        while (start < S.size() && S[start] != '-') {
            val *= 10;
            val += (int)(S[start] - '0');
            start++;
        }
        return val;
    }
};

//////////////////////////////////////////////////////////////////////////
TreeNode* _solution_run(string S)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.recoverFromPreorder(S);
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
