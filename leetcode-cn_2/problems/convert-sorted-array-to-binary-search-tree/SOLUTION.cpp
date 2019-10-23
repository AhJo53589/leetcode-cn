
//////////////////////////////////////////////////////////////////////////
TreeNode* sortedArrayToBST(vector<int>& nums, size_t _First, size_t _Last)
{
	if (_Last <= _First) return NULL;

	size_t _Mid = _First + (_Last - _First) / 2;
	TreeNode *pNode = new TreeNode(nums[_Mid]);
	TreeNode *pLeft = sortedArrayToBST(nums, _First, _Mid);
	TreeNode *pRight = sortedArrayToBST(nums, _Mid + 1, _Last);
	pNode->left = pLeft;
	pNode->right = pRight;
	return pNode;
}

TreeNode* sortedArrayToBST(vector<int>& nums)
{
	size_t _First = 0;
	size_t _Last = nums.size();
	if (_Last == 0) return NULL;

	return sortedArrayToBST(nums, _First, _Last);
}

//////////////////////////////////////////////////////////////////////////
TreeNode* _solution_run(vector<int>& nums)
{
	return sortedArrayToBST(nums);
}

//#define USE_SOLUTION_CUSTOM
//TreeNode* _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {
};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/convert-sorted-array-to-binary-search-tree/tests.txt";
}

