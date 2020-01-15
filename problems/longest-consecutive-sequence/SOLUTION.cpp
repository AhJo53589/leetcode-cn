
//////////////////////////////////////////////////////////////////////////
// ¹þÏ£
int longestConsecutive(vector<int>& nums) 
{
    if (nums.size() < 2)return nums.size();
    int res = 0;
    unordered_map<int, int> hashmap;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (hashmap.count(nums[i]) == 0)
        {
            int left = 0, right = 0;
            if (hashmap.count(nums[i] - 1) > 0)
            {
                left = hashmap[nums[i] - 1];
            }
            if (hashmap.count(nums[i] + 1) > 0)
            {
                right = hashmap[nums[i] + 1];
            }
            hashmap[nums[i]] = left + right + 1;
            if (left != 0)
            {
                hashmap[nums[i] - left] = left + right + 1;
            }
            if (right != 0)
            {
                hashmap[nums[i] + right] = left + right + 1;
            }
            res = max(res, left + right + 1);
        }
    }
    return res;
}



//////////////////////////////////////////////////////////////////////////
// ÅÅÐò
//class Solution {
//public:
//    int longestConsecutive(vector<int>& nums)
//    {
//        if (nums.size() == 0) return 0;
//        sort(nums.begin(), nums.end());
//
//        int ans = 1;
//        int temp = 1;
//        for (int i = 1; i < nums.size(); i++)
//        {
//            if (nums[i] == nums[i - 1]) continue;
//            temp = (nums[i] == nums[i - 1] + 1) ? temp + 1 : 1;
//            ans = max(ans, temp);
//        }
//
//        return ans;
//    }
//};



//////////////////////////////////////////////////////////////////////////
// ²¢²é¼¯
//class Solution {
//public:
//    int find(int x)
//    {
//        return (x == parnet[x]) ? x : (parnet[x] = find(parnet[x]));
//    }
//
//    void unite(int x, int y)
//    {
//        if (parnet.count(x) == 0) return;
//        if (parnet.count(y) == 0) return;
//        int x0 = find(x);
//        int y0 = find(y);
//        if (x0 == y0) return;
//        if (sz[x0] < sz[y0])
//        {
//            swap(x0, y0);
//        }
//        parnet[y0] = x0;
//        sz[x0] += sz[y0];
//    }
//
//    int longestConsecutive(vector<int>& nums)
//    {
//        int ans = 0;
//        for (auto& n : nums)
//        {
//            if (parnet.count(n) != 0) continue;
//            parnet[n] = n;
//            sz[n] = 1;
//
//            unite(n, n - 1);
//            unite(n, n + 1);
//            ans = max(ans, sz[find(n)]);
//        }
//        return ans;
//    }
//
//private:
//    unordered_map<int, int> parnet;
//    unordered_map<int, int> sz;
//};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
    Solution sln;
	return sln.longestConsecutive(nums);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
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
	return "../../problems/longest-consecutive-sequence/tests.txt";
}

