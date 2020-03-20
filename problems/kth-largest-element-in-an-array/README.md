# `（中等）` [215.kth-largest-element-in-an-array 数组中的第K个最大元素](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)

### 题目描述
<p>在未排序的数组中找到第 <strong>k</strong> 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> <code>[3,2,1,5,6,4] 和</code> k = 2
<strong>输出:</strong> 5
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> <code>[3,2,3,1,2,4,5,5,6] 和</code> k = 4
<strong>输出:</strong> 4</pre>

<p><strong>说明: </strong></p>

<p>你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。</p>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/solution/215-by-ikaruga/)

### 答题
``` C++
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

```


### 其它
``` C++
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

```


