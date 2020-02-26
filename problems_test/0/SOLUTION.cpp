
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
            int mid = left + ((right - left + 1) >> 1);  // 取右中位数
            // 这种情况无法二分 => 因为至少要找到一部分有序区间。此时只能顺序查找。
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

            if (nums[mid] <= nums[right]) {  // 这里这个等号至关重要（记住“旋转数组”题目，判断nums[mid]和两边界的大小时，要加个等号）！！  不加等号就错了，特例：{3, 1}  3  
                // 使用上取整的中间数，必须在上面的 mid 表达式的括号里 + 1
                // 重要：把比较好写的判断（如 target 落在有序区间的那部分）放在 if 的开头考虑，把剩下的情况放在 else 里面。（即 先写好写的条件）
                if (nums[mid] <= target && target <= nums[right]) {
                    // 下一轮搜索区间是 [mid, right]
                    left = mid;   // 这里决定了我们的mid要选“右中位数”
                }
                else {
                    // 只要上面对了，这里不用思考，可以一下子写出来
                    right = mid - 1;
                }

            }
            else {
                // [left, mid] 有序，但是为了和上一个 if 有同样的收缩行为，（收缩右边界）
                // 我们故意只认为 [left, mid - 1] 有序
                // 当区间只有 2 个元素的时候 int mid = (left + right + 1) >>> 1; 一定会取到右边
                // 此时 mid - 1 不会越界，就是这么刚刚好

                //if (nums[left] <= target && target <= nums[mid - 1]) {  // 这是大佬写法
                if (nums[left] <= target && target < nums[mid]) {  // 这样写是有条件的
                    // 下一轮搜索区间是 [left, mid - 1]
                    right = mid - 1;  // （保证了）和上面同样的收缩行为
                }
                else {
                    // 同理，只要上面对了，这里不用思考，可以一下子写出来
                    left = mid;
                }
            }
        }

        // 有可能区间内不存在目标元素，因此还需做一次判断
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
