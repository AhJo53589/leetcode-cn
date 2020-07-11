
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findNthDigit(int n) {
        // ����������ɼ�λ������ɣ���1λ��digits = 1��2λ��digits = 2...
        long base = 9, digits = 1;
        while (n - base * digits > 0) {
            n -= base * digits;
            base *= 10;
            digits++;
        }

        // ������ʵ����������Ƕ���
        int idx = n % digits;  // ע����������ļ��㣬n���ڱ�ʾdigitsλ���ĵ�n������
        if (idx == 0)idx = digits;
        long number = 1;
        for (int i = 1; i < digits; i++)
            number *= 10;
        number += (idx == digits) ? n / digits - 1 : n / digits;

        // ����ʵ���������ҵ�������Ҫ���Ǹ�����
        for (int i = idx; i < digits; i++) number /= 10;
        return number % 10;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.findNthDigit(n);
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
