


//////////////////////////////////////////////////////////////////////////
int removeDuplicates(vector<int>& nums)
{
	int iLen = nums.size();
	if (nums.size() < 2) return iLen;

	int iIndex = 1;
	for (int i = 2; i < iLen; i++)
	{
		if (nums[i] != nums[iIndex - 1])
		{
			nums[++iIndex] = nums[i];
		}
	}
	return iIndex + 1;
}

//////////////////////////////////////////////////////////////////////////
//int _solution_run(vector<int>& nums)
//{
//	return removeDuplicates(nums);
//}

#define USE_SOLUTION_CUSTOM
vector<int> _solution_custom(TestCases &tc)
{
	vector<int> nums = tc.get<vector<int>>();
	vector<int> ans;

	// nums ���ԡ����á���ʽ���ݵġ�Ҳ����˵������ʵ�����κο���
	int len = removeDuplicates(nums);

	// �ں������޸�����������ڵ������ǿɼ��ġ�
	// ������ĺ������صĳ���, �����ӡ�������иó��ȷ�Χ�ڵ�����Ԫ�ء�
	for (int i = 0; i < len; i++)
	{
		ans.push_back(nums[i]);
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

