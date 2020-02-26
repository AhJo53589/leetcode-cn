
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) {
            return -1;
        }

        cout << nums.size() << endl;
        int left = 0;
        int right = len - 1;
        while (left < right) {
            int mid = left + ((right - left + 1) >> 1);  // ȡ����λ��
            // ��������޷����� => ��Ϊ����Ҫ�ҵ�һ�����������䡣��ʱֻ��˳����ҡ�
            if (nums[mid] == nums[left] && nums[mid] == nums[right]) {
                int left2 = findNum(nums, left, right, target);
                int res = -1;
                for (int i = left; i >= 0; i--) {
                    if (nums[i] == target)
                        res = i;
                    else
                        break;
                }
                return res;
            }

            if (nums[mid] <= nums[right]) {  // ��������Ⱥ�������Ҫ����ס����ת���顱��Ŀ���ж�nums[mid]�����߽�Ĵ�Сʱ��Ҫ�Ӹ��Ⱥţ�����  ���ӵȺžʹ��ˣ�������{3, 1}  3  
                // ʹ����ȡ�����м���������������� mid ���ʽ�������� + 1
                // ��Ҫ���ѱȽϺ�д���жϣ��� target ��������������ǲ��֣����� if �Ŀ�ͷ���ǣ���ʣ�µ�������� else ���档���� ��д��д��������
                if (nums[mid] <= target && target <= nums[right]) {
                    // ��һ������������ [mid, right]
                    left = mid;   // ������������ǵ�midҪѡ������λ����
                }
                else {
                    // ֻҪ������ˣ����ﲻ��˼��������һ����д����
                    right = mid - 1;
                }

            }
            else {
                // [left, mid] ���򣬵���Ϊ�˺���һ�� if ��ͬ����������Ϊ���������ұ߽磩
                // ���ǹ���ֻ��Ϊ [left, mid - 1] ����
                // ������ֻ�� 2 ��Ԫ�ص�ʱ�� int mid = (left + right + 1) >>> 1; һ����ȡ���ұ�
                // ��ʱ mid - 1 ����Խ�磬������ô�ոպ�

                //if (nums[left] <= target && target <= nums[mid - 1]) {  // ���Ǵ���д��
                if (nums[left] <= target && target < nums[mid]) {  // ����д����������
                    // ��һ������������ [left, mid - 1]
                    right = mid - 1;  // ����֤�ˣ�������ͬ����������Ϊ
                }
                else {
                    // ͬ��ֻҪ������ˣ����ﲻ��˼��������һ����д����
                    left = mid;
                }
            }
        }

        // �п��������ڲ�����Ŀ��Ԫ�أ���˻�����һ���ж�
        if (nums[left] == target) {
            int res = -1;
            for (int i = left; i >= 0; i--) {
                if (nums[i] == target)
                    res = i;
                else
                    break;
            }
            return res;
        }
        return -1;
    }

    int findNum(vector<int>& nums, int left, int right, int target) {
        cout << left << " " << nums[left] << " " << nums[63] << endl;
        for (auto num : nums)
            cout << num << " ";
        cout << endl;
        for (int i = left; i <= right; i++) {
            if (nums[i] == target)
                return i;
        }
        return -1;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& arr, int target)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.search(arr, target);
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
