# `（中等）` [5402.longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit 绝对差不超过限制的最长连续子数组](https://leetcode-cn.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/)

[contest](https://leetcode-cn.com/contest/weekly-contest-187/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/)

### 题目描述
<p>给你一个整数数组 <code>nums</code> ，和一个表示限制的整数 <code>limit</code>，请你返回最长连续子数组的长度，该子数组中的任意两个元素之间的绝对差必须小于或者等于 <code>limit</code><em> 。</em></p>

<p>如果不存在满足条件的子数组，则返回 <code>0</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [8,2,4,7], limit = 4
<strong>输出：</strong>2 
<strong>解释：</strong>所有子数组如下：
[8] 最大绝对差 |8-8| = 0 <= 4.
[8,2] 最大绝对差 |8-2| = 6 > 4. 
[8,2,4] 最大绝对差 |8-2| = 6 > 4.
[8,2,4,7] 最大绝对差 |8-2| = 6 > 4.
[2] 最大绝对差 |2-2| = 0 <= 4.
[2,4] 最大绝对差 |2-4| = 2 <= 4.
[2,4,7] 最大绝对差 |2-7| = 5 > 4.
[4] 最大绝对差 |4-4| = 0 <= 4.
[4,7] 最大绝对差 |4-7| = 3 <= 4.
[7] 最大绝对差 |7-7| = 0 <= 4. 
因此，满足题意的最长子数组的长度为 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [10,1,2,4,7,2], limit = 5
<strong>输出：</strong>4 
<strong>解释：</strong>满足题意的最长子数组是 [2,4,7,2]，其最大绝对差 |2-7| = 5 <= 5 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [4,2,2,2,4,4,2,2], limit = 0
<strong>输出：</strong>3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10^5</code></li>
	<li><code>1 <= nums[i] <= 10^9</code></li>
	<li><code>0 <= limit <= 10^9</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/solution/longest-continuous-subarray-by-ikaruga/)

### 答题
``` C++
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> s;
        int ans = 0;
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            s.insert(nums[j]);

            if (*s.rbegin() - *s.begin() <= limit) {
                ans = max(ans, j - i + 1);
                continue;
            }

            s.erase(s.find(nums[i]));
            i++;
        }
        return ans;
    }
```




