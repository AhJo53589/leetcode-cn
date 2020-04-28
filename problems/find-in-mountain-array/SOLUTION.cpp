//////////////////////////////////////////////////////////////////////////
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class MountainArray {
public:
    MountainArray(vector<int> arr) : data(arr) {

    }

    int get(int index) {
        cnt++;
        return (index < 0 || index >= data.size()) ? 0 : data[index];
    }

    int length() {
        return data.size();
    }

    bool wrong() {
        return cnt >= 100;
    }

private:
    vector<int> data;
    int cnt = 0;
};

//////////////////////////////////////////////////////////////////////////
class Solution {
    int binary_search(MountainArray& mountain, int target, int l, int r, int key(int)) {
        target = key(target);
        while (l <= r) {
            int mid = (l + r) / 2;
            int cur = key(mountain.get(mid));
            if (cur == target)
                return mid;
            else if (cur < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray& mountainArr) {
        int l = 0, r = mountainArr.length() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                l = mid + 1;
            else
                r = mid;
        }

        int peak = l;
        int index = binary_search(mountainArr, target, 0, peak, [](int x) -> int {return x; });
        if (index != -1)
            return index;
        return binary_search(mountainArr, target, peak + 1, mountainArr.length() - 1, [](int x) -> int {return -x; });
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int> &arr, int target)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    MountainArray mountainArr(arr);
    Solution sln;
    int ans = sln.findInMountainArray(target, mountainArr);
    return mountainArr.wrong() ? -2 : ans;
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//    return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
