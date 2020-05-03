
//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int, int> m;
        int ans = 0;
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            m[nums[j]]++;
            while (m.rbegin()->first - m.begin()->first > limit) {
                m[nums[i]]--;
                if (m[nums[i]] == 0) {
                    m.erase(nums[i]);
                }
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> s;
        int ans = 0;
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            s.insert(nums[j]);
            while (*s.rbegin() - *s.begin() > limit) {
                s.erase(s.find(nums[i]));
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums, int limit)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(nums);
    cout << limit << endl;
    Solution2 sln;
    return sln.longestSubarray(nums, limit);
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
