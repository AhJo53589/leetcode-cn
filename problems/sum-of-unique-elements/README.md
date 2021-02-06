# `（简单）` [5657.sum-of-unique-elements 唯一元素的和](https://leetcode-cn.com/problems/sum-of-unique-elements/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-45/problems/sum-of-unique-elements/)

### 题目描述
<div class="notranslate"><p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;。数组中唯一元素是那些只出现&nbsp;<strong>恰好一次</strong>&nbsp;的元素。</p>

<p>请你返回 <code>nums</code>&nbsp;中唯一元素的 <strong>和</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,2,3,2]
<b>输出：</b>4
<b>解释：</b>唯一元素为 [1,3] ，和为 4 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,1,1,1,1]
<b>输出：</b>0
<b>解释：</b>没有唯一元素，和为 0 。
</pre>

<p><strong>示例 3 ：</strong></p>

<pre><b>输入：</b>nums = [1,2,3,4,5]
<b>输出：</b>15
<b>解释：</b>唯一元素为 [1,2,3,4,5] ，和为 15 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>
</div>

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/sum-of-unique-elements/solution/sum-of-unique-elements-by-ikaruga-63dw/)

### 答题
``` C++
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> cnt;
        for (auto& n : nums) {
            cnt[n]++;
            ans += (cnt[n] == 1) ? n : 0;
            ans -= (cnt[n] == 2) ? n : 0;
        }
        return ans;
    }
};
```




