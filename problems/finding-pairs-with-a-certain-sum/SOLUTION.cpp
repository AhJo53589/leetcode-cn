
//////////////////////////////////////////////////////////////////////////
class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : nums(nums2) {
        for (auto n : nums1) {
            um1[n]++;
        }
        for (auto n : nums2) {
            um2[n]++;
        }
    }

    void add(int index, int val) {
        um2[nums[index]]--;
        nums[index] += val;
        um2[nums[index]]++;
    }

    int count(int tot) {
        int ans = 0;
        for (auto [val, cnt] : um1) {
            int df = tot - val;
            if (df < 0) continue;
            if (um2.find(df) == um2.end()) continue;
            ans += um2[df] * cnt;
        }
        return ans;
    }

private:
    unordered_map<int, int> um1;
    unordered_map<int, int> um2;
    vector<int> nums;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */

 //////////////////////////////////////////////////////////////////////////
 //int _solution_run(int)
 //{
 //}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases& tc)
{
    vector<string> sf = tc.get<vector<string>>();
    vector<string> sp = tc.get<vector<string>>();
    vector<string> ans;

    FindSumPairs* obj = nullptr;
    for (auto i = 0; i < sf.size(); i++)
    {
        if (sf[i] == "FindSumPairs")
        {
            TestCases stc(sp[i]);
            vector<int> nums1 = stc.get<vector<int>>();
            vector<int> nums2 = stc.get<vector<int>>();
            obj = new FindSumPairs(nums1, nums2);
            ans.push_back("null");
        }
        else if (sf[i] == "add")
        {
            TestCases stc(sp[i]);
            int index = stc.get<int>();
            int val = stc.get<int>();
            obj->add(index, val);
            ans.push_back("null");
        }
        else if (sf[i] == "count")
        {
            TestCases stc(sp[i]);
            int tot = stc.get<int>();
            int r = obj->count(tot);
            ans.push_back(convert<string>(r));
        }
    }
    delete obj;

    return convert<string>(ans);
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
