# `（简单）` [414.third-maximum-number 第三大的数](https://leetcode-cn.com/problems/third-maximum-number/)

### 题目描述
<p>给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> [3, 2, 1]

<strong>输出:</strong> 1

<strong>解释:</strong> 第三大的数是 1.
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> [1, 2]

<strong>输出:</strong> 2

<strong>解释:</strong> 第三大的数不存在, 所以返回最大的数 2 .
</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入:</strong> [2, 2, 3, 1]

<strong>输出:</strong> 1

<strong>解释:</strong> 注意，要求返回第三大的数，是指第三大且唯一出现的数。
存在两个值为2的数，它们都排第二。
</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/third-maximum-number/solution/third-maximum-number-by-ikaruga/)

### 答题
``` C++
    int thirdMax(vector<int>& nums) {
        vector<int> ans;
        for (auto n : nums) {
            if (any_of(ans.begin(), ans.end(), [n](const int& a) { return a == n; })) {
                continue;
            }

            for (int i = 0; i < ans.size(); i++) {
                if (n > ans[i]) {
                    swap(n, ans[i]);
                }
            }

            if (ans.size() < 3) {
                ans.push_back(n);
            }
        }

        if (ans.empty()) return 0;
        if (ans.size() < 3) return ans.front();
        return ans.back();
    }
```




