
// ��һ������ΪN����Ȼ������ values ,  ���Զ�����������������ֲ�����ÿ�ֲ����������ޣ���
//    1. ������������������λ�õ� ���֣�
//    2. ѡ��������ĳһ������ 0 �滻�������������
// �ж��Ƿ���ͨ��һЩ������ʹ�� values �е�Ԫ���Ƿ����� values[i 1]=values[i] 1  (0 <= i < N-1)��

// 1 <=  N <= 10^6
// 0 <= Values[I] <= 10^9

//////////////////////////////////////////////////////////////////////////
bool otaku(vector<int>& nums) {
    if (nums.size() <= 1) return true;
    sort(nums.begin(),nums.end());
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i]!=0) break;
        cnt++;
    }
    if (cnt == nums.size()) return true;
    for (int i = cnt; i < nums.size()-1; i++) {
        if (nums[i] == nums[i+1]) return false;
        else cnt -= nums[i+1]-nums[i]-1;

    }
    return cnt >= 0;
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& nums)
{
	return otaku(nums);
}

//#define USE_SOLUTION_CUSTOM
//bool _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/one-day-of-otaku/tests.txt";
}

