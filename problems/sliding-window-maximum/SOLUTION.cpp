
//////////////////////////////////////////////////////////////////////////
//void nextPermutation(vector<int>& nums) 
//{
//    if (nums.empty()) return;
//
//    vector<int> vec;
//    for (size_t i = nums.size() - 1; i > 0;)
//    {
//        i--;
//        vec.push_back(nums[i + 1]);
//        if (nums[i] < nums[i + 1])
//        {
//            sort(vec.begin(), vec.end());
//            auto it = lower_bound(vec.begin(), vec.end(), nums[i]);
//            swap(nums[i], *it);
//            for (size_t j = 0; j < vec.size(); j++)
//            {
//                nums[j + i + 1] = vec[j];
//            }
//            break;
//        }
//    }
//}

//////////////////////////////////////////////////////////////////////////
//vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//    if (k <= 1)
//        return nums;
//    else {
//        deque<int> d;
//        d.push_back(0);
//        for (int i = 1; i < k; i++) {
//            if (nums[d.back()] > nums[i])
//                d.push_back(i);
//            else {
//                while (!d.empty() && nums[d.back()] < nums[i])
//                    d.pop_back();
//                d.push_back(i);
//            }
//        }
//        vector<int> res;
//        res.clear();
//        res.push_back(nums[d.front()]);
//        for (int i = k; i < nums.size(); i++) {
//            if (d.front() < i - k + 1)
//                d.pop_front();
//            if (nums[d.back()] > nums[i])
//                d.push_back(i);
//            else {
//                while (!d.empty() && nums[d.back()] < nums[i])
//                    d.pop_back();
//                d.push_back(i);
//            }
//            res.push_back(nums[d.front()]);
//        }
//        return res;
//    }
//}

//////////////////////////////////////////////////////////////////////////
//vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//    vector<int> res;
//    deque<int> dq;
//    for (int i = 0; i < nums.size(); i++) {
//        while (!dq.empty() && nums[i] > nums[dq.back()]) dq.pop_back();
//        dq.push_back(i);
//        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
//        if (i >= k - 1) res.push_back(nums[dq.front()]);
//    }
//    return res;
//}


//////////////////////////////////////////////////////////////////////////
vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    vector<int> ans;
    priority_queue<int> del_queue;
    priority_queue<int> cur_queue;

    for (size_t i = 0; i < nums.size(); i++)
    {
        cur_queue.push(nums[i]);
        if (i < k - 1) continue;

        ans.push_back(cur_queue.top());
        del_queue.push(nums[i - k + 1]);
        while (!cur_queue.empty() && !del_queue.empty() && cur_queue.top() == del_queue.top())
        {
            cur_queue.pop();
            del_queue.pop();
        }
    }
    return ans;
}


//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums, int k)
{
    return maxSlidingWindow(nums,k);
}

//#define USE_SOLUTION_CUSTOM
//vector<int> _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}

