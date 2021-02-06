# `（中等）` [5658.maximum-absolute-sum-of-any-subarray 任意子数组和的绝对值的最大值](https://leetcode-cn.com/problems/maximum-absolute-sum-of-any-subarray/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-45/problems/maximum-absolute-sum-of-any-subarray/)

### 题目描述
<div class="notranslate"><p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;。一个子数组&nbsp;<code>[nums<sub>l</sub>, nums<sub>l+1</sub>, ..., nums<sub>r-1</sub>, nums<sub>r</sub>]</code>&nbsp;的 <strong>和的绝对值</strong>&nbsp;为&nbsp;<code>abs(nums<sub>l</sub> + nums<sub>l+1</sub> + ... + nums<sub>r-1</sub> + nums<sub>r</sub>)</code>&nbsp;。</p>

<p>请你找出 <code>nums</code>&nbsp;中 <strong>和的绝对值</strong> 最大的任意子数组（<b>可能为空</b>），并返回该 <strong>最大值</strong>&nbsp;。</p>

<p><code>abs(x)</code>&nbsp;定义如下：</p>

<ul>
	<li>如果&nbsp;<code>x</code>&nbsp;是负整数，那么&nbsp;<code>abs(x) = -x</code>&nbsp;。</li>
	<li>如果&nbsp;<code>x</code>&nbsp;是非负整数，那么&nbsp;<code>abs(x) = x</code>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,-3,2,3,-4]
<b>输出：</b>5
<b>解释：</b>子数组 [2,3] 和的绝对值最大，为 abs(2+3) = abs(5) = 5 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [2,-5,1,-4,3,-2]
<b>输出：</b>8
<b>解释：</b>子数组 [-5,1,-4] 和的绝对值最大，为 abs(-5+1-4) = abs(-8) = 8 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>
</div>

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/maximum-absolute-sum-of-any-subarray/solution/maximum-absolute-sum-by-ikaruga-omob/)

### 答题
``` C++
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        return max(maxSubArray(nums, 1), maxSubArray(nums, -1));
    }

    int maxSubArray(vector<int>& nums, int p) {
        if (nums.empty()) return 0;
        int dp = p * nums[0];
        int ans = dp;
        for (int i = 1; i < nums.size(); i++) {
            int n = p * nums[i];
            dp = max(dp + n, n);
            ans = max(ans, dp);
        }
        return ans;
    }
};
```




