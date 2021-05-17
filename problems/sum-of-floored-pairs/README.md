# `（困难）` [1862.sum-of-floored-pairs 向下取整数对和](https://leetcode-cn.com/problems/sum-of-floored-pairs/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-52/problems/sum-of-floored-pairs/)

### 题目描述
<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;，请你返回所有下标对&nbsp;<code>0 &lt;= i, j &lt; nums.length</code>&nbsp;的&nbsp;<code>floor(nums[i] / nums[j])</code>&nbsp;结果之和。由于答案可能会很大，请你返回答案对<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;的结果。</p>

<p>函数&nbsp;<code>floor()</code>&nbsp;返回输入数字的整数部分。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [2,5,9]
<b>输出：</b>10
<strong>解释：</strong>
floor(2 / 5) = floor(2 / 9) = floor(5 / 9) = 0
floor(2 / 2) = floor(5 / 5) = floor(9 / 9) = 1
floor(5 / 2) = 2
floor(9 / 2) = 4
floor(9 / 5) = 1
我们计算每一个数对商向下取整的结果并求和得到 10 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [7,7,7,7,7,7,7]
<b>输出：</b>49
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
private:
    static constexpr int mod = 1000000007;

    using LL = long long;

public:
    int sumOfFlooredPairs(vector<int>& nums) {
        // 元素最大值
        int upper = *max_element(nums.begin(), nums.end());
        vector<int> cnt(upper + 1);
        for (int num : nums) {
            ++cnt[num];
        }
        // 预处理前缀和
        vector<int> pre(upper + 1);
        for (int i = 1; i <= upper; ++i) {
            pre[i] = pre[i - 1] + cnt[i];
        }

        LL ans = 0;
        for (int y = 1; y <= upper; ++y) {
            // 一个小优化，如果数组中没有 y 可以跳过
            if (cnt[y]) {
                for (int d = 1; d * y <= upper; ++d) {
                    ans += (LL)cnt[y] * d * (pre[min((d + 1) * y - 1, upper)] - pre[d * y - 1]);
                }
            }
        }
        return ans % mod;
    }
};
```




