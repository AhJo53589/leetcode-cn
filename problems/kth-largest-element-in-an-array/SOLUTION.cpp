
//////////////////////////////////////////////////////////////////////////
class Solution3 {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& n : nums)
        {
            if (pq.size() >= k && pq.top() >= n) continue;
            pq.push(n);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        return pq.top();
    }
};

class Solution2 {
public:
    void adjustHeap(vector<int>& hp, int idx, function<bool(const int& a, const int& b)> cmp)
    {
        for (int i = idx; i * 2 + 1 < hp.size();)
        {
            int t = i * 2 + 1;
            t += (t + 1 < hp.size() && !cmp(hp[t + 1], hp[t]));
            if (!cmp(hp[i], hp[t])) break;
            swap(hp[i], hp[t]);
            i = t;
        }
    }

    void buildHeap(vector<int>& hp, function<bool(const int& a, const int& b)> cmp)
    {
        for (int i = hp.size() / 2 - 1; i >= 0; i--)
        {
            adjustHeap(hp, i, cmp);
        }
    }

    int findKthLargest(vector<int>& nums, int k)
    {
        if (k == 0) return {};
        vector<int> ans(nums.begin(), nums.begin() + k);
        auto cmp_less = [](const int& a, const int& b) { return a < b; };
        auto cmp_greater = [](const int& a, const int& b) { return a > b; };
        auto cmp = cmp_greater;
        buildHeap(ans, cmp);
        for (int i = k; i < nums.size(); i++)
        {
            if (!cmp(nums[i], ans[0])) continue;
            ans[0] = nums[i];
            adjustHeap(ans, 0, cmp);
        }
        return ans[0];
    }
};

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        int len = nums.size();
        bool bOrder = k <= len / 2;
        int t = bOrder ? k : len - k + 1;
        for (int j = 0; j < len - 1; j++)
        {
            for (int i = 0; i < len - 1 - j; i++)
            {
                if ([bOrder](int a, int b) { return bOrder ? a > b : b > a; }(nums[i], nums[i + 1]))
                {
                    swap(nums[i], nums[i + 1]);
                }
            }
            if (t-- == 0) break;
        }
        return bOrder ? nums[len - k] : nums[k - 1];
    }
};


//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums, int k)
{
    printVectorT(nums);
    cout << k << endl;
    Solution3 sln;
    return sln.findKthLargest(nums,k);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}

