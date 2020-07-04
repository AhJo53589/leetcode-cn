
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return verify(postorder, 0, postorder.size() - 1, INT_MIN, INT_MAX);
    }

    bool verify(vector<int>& postorder, int left, int right, int minVal, int maxVal) {
        if (left >= right) return true;

        int key = postorder[right];
        right--;
        int split = -1;

        for (int i = left; i <= right; i++) {
            if (postorder[i] < minVal || postorder[i] > maxVal) return false;
            if (split != -1 && postorder[i] < key) return false;
            if (split == -1 && postorder[i] > key) {
                split = i;
            }
        }

        if (split == -1) return verify(postorder, left, right, minVal, key);

        return verify(postorder, left, split - 1, minVal, key) && verify(postorder, split, right, key, maxVal);
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& postorder)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.verifyPostorder(postorder);
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
