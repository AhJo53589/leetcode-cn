
// ����������A��B�����ֲ����ֱ��� + 12�� - 12�� + 7�� - 7�� + 5�� - 5��
// A�������ɴβ��������B ����������2����A��B��Ҫ�����任���̣������еĲ������о���һ��·����Ҳ�������ٵĲ������� ��
// ����˼·�ʹ���

//////////////////////////////////////////////////////////////////////////
// ���ص� vector<int> Ϊ���ֲ����Ĳ���������[0] = +12��[1] = -12��[2] = +7��[3] = -7��[4] = +5��[5] = -5
// �� {0,0,1,0,0,1} ��ʾ��1 �� +7 �� 1 �� -5
class Solution {
public:
	vector<int> minMove(int A, int B) {

    }

private:
	vector<int> op = { 12,-12,7,-7,5,-5 };
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int> nums)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.minMove(nums[0], nums[1]);
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
