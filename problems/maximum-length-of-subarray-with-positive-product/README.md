# `（中等）` [5500.maximum-length-of-subarray-with-positive-product 乘积为正数的最长子数组长度](https://leetcode-cn.com/problems/maximum-length-of-subarray-with-positive-product/)

[contest](https://leetcode-cn.com/contest/weekly-contest-204/problems/maximum-length-of-subarray-with-positive-product/)

### 题目描述
<p>给你一个整数数组 <code>nums</code>&nbsp;，请你求出乘积为正数的最长子数组的长度。</p>

<p>一个数组的子数组是由原数组中零个或者更多个连续数字组成的数组。</p>

<p>请你返回乘积为正数的最长子数组长度。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp; 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,-2,-3,4]
<strong>输出：</strong>4
<strong>解释：</strong>数组本身乘积就是正数，值为 24 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [0,1,-2,-3,-4]
<strong>输出：</strong>3
<strong>解释：</strong>最长乘积为正数的子数组为 [1,-2,-3] ，乘积为 6 。
注意，我们不能把 0 也包括到子数组中，因为这样乘积为 0 ，不是正数。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [-1,-2,-3,0,1]
<strong>输出：</strong>2
<strong>解释：</strong>乘积为正数的最长子数组是 [-1,-2] 或者 [-2,-3] 。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>nums = [-1,2]
<strong>输出：</strong>1
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3,5,-6,4,0,10]
<strong>输出：</strong>4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10^5</code></li>
	<li><code>-10^9 <= nums[i]&nbsp;<= 10^9</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/maximum-length-of-subarray-with-positive-product/solution/maximum-length-of-subarray-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int ans = 0;
        int bg = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) continue;
            ans = max(ans, getMaxLen(nums, bg, i));
            bg = i + 1;
        }
        ans = max(ans, getMaxLen(nums, bg, nums.size()));
        return ans;
    }

    int getMaxLen(vector<int>& nums, int bg, int ed) {
        int cnt = 0;
        int l = -1;
        int r = -1;
        for (int i = bg; i < ed; i++) {
            if (nums[i] > 0) continue;
            cnt++;
            l = (l == -1) ? i : l;
            r = i;
        }
        if (cnt % 2 == 0) return ed - bg;
        return max(ed - (l + 1), r - bg);
    }
};
```




