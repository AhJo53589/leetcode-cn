
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        ans += postOrder(root) == 2;
        return ans;
    }

    // 返回值表示与摄像头的距离
    int postOrder(TreeNode* root) {
        if (root == nullptr) return 1;

        int l = postOrder(root->left);
        int r = postOrder(root->right);

        int ret = min(l, r) + 1;
        if (max(l, r) == 2) {
            ret = 0;
            ans++;
        }
        return ret;
    }

private:
    int ans = 0;
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(TreeNode* root)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.minCameraCover(root);
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
