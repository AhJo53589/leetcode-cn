
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        this->target = target;
        this->k = k;
        findTarget(root);
        return ans;
    }

    int findTarget(TreeNode* node) {
        if (node == nullptr) return -1;
        if (node == target) {
            checkDis(node, 0);
            return 1;
        }

        int dis = findTarget(node->left);
        if (dis != -1) {
            checkDis(node, dis, false, true);
            return dis + 1;
        }

        dis = findTarget(node->right);
        if (dis != -1) {
            checkDis(node, dis, true, false);
            return dis + 1;
        }
        return -1;
    }

    void checkDis(TreeNode* node, int dis, bool left = true, bool right = true) {
        if (node == nullptr) return;
        if (dis == k) {
            ans.push_back(node->val);
            return;
        }
        if (left) {
            checkDis(node->left, dis + 1);
        }
        if (right) {
            checkDis(node->right, dis + 1);
        }
    }

private:
    TreeNode* target;
    int k;
    vector<int> ans;
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(TreeNode* root, TreeNode* target, int k)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.distanceK(root, target, k);
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
