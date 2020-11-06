# `（简单）` [5539.sort-array-by-increasing-frequency 按照频率将数组升序排序](https://leetcode-cn.com/problems/sort-array-by-increasing-frequency/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-38/problems/sort-array-by-increasing-frequency/)

### 题目描述
<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;，请你将数组按照每个值的频率 <strong>升序</strong> 排序。如果有多个值的频率相同，请你按照数值本身将它们 <strong>降序</strong> 排序。&nbsp;</p>

<p>请你返回排序后的数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,1,2,2,2,3]
<b>输出：</b>[3,1,1,2,2,2]
<b>解释：</b>'3' 频率为 1，'1' 频率为 2，'2' 频率为 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [2,3,1,3,2]
<b>输出：</b>[1,3,3,2,2]
<b>解释：</b>'2' 和 '3' 频率都为 2 ，所以它们之间按照数值本身降序排序。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [-1,1,-6,4,5,-6,1,4,1]
<b>输出：</b>[5,-1,4,4,-6,-6,1,1,1]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>-100 &lt;= nums[i] &lt;= 100</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/sort-array-by-increasing-frequency/solution/sort-array-by-increasing-frequency-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (auto n : nums) {
            cnt[n]++;
        }
        sort(nums.begin(), nums.end(), [&cnt](int a, int b) {
            return (cnt[a] == cnt[b]) ? a > b : cnt[a] < cnt[b];
        });
        return nums;
    }
};
```




