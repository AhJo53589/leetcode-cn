# `（中等）` [1437.check-if-all-1s-are-at-least-length-k-places-away 是否所有 1 都至少相隔 k 个元素](https://leetcode-cn.com/problems/check-if-all-1s-are-at-least-length-k-places-away/)

[contest](https://leetcode-cn.com/contest/weekly-contest-187/problems/check-if-all-1s-are-at-least-length-k-places-away/)

### 题目描述
<p>给你一个由若干 <code>0</code> 和 <code>1</code> 组成的数组 <code>nums</code> 以及整数 <code>k</code>。如果所有 <code>1</code> 都至少相隔 <code>k</code> 个元素，则返回 <code>True</code> ；否则，返回 <code>False</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img style="width: 214px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/05/03/sample_1_1791.png" alt=""></strong></p>

<pre><strong>输入：</strong>nums = [1,0,0,0,1,0,0,1], k = 2
<strong>输出：</strong>true
<strong>解释：</strong>每个 1 都至少相隔 2 个元素。</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img style="height: 86px; width: 160px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/05/03/sample_2_1791.png" alt=""></strong></p>

<pre><strong>输入：</strong>nums = [1,0,0,1,0,1], k = 2
<strong>输出：</strong>false
<strong>解释：</strong>第二个 1 和第三个 1 之间只隔了 1 个元素。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [1,1,1,1,1], k = 0
<strong>输出：</strong>true
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>nums = [0,1,0,1], k = 1
<strong>输出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10^5</code></li>
	<li><code>0 <= k <= nums.length</code></li>
	<li><code>nums[i]</code> 的值为 <code>0</code> 或 <code>1</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/check-if-all-1s-are-at-least-length-k-places-away/solution/check-if-all-1s-are-at-least-length-k-places-away-/)

### 答题
``` C++
    bool kLengthApart(vector<int>& nums, int k) {
        int t = k;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1 && t < k) return false;
            t = (nums[i] == 0) ? t + 1 : 0;
        }
        return true;
    }
```




