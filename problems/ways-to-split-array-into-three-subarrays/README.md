# `（中等）` [5643.ways-to-split-array-into-three-subarrays 将数组分成三个子数组的方案数](https://leetcode-cn.com/problems/ways-to-split-array-into-three-subarrays/)

[contest](https://leetcode-cn.com/contest/weekly-contest-222/problems/ways-to-split-array-into-three-subarrays/)

### 题目描述
<div class="notranslate"><p>我们称一个分割整数数组的方案是 <strong>好的</strong>&nbsp;，当它满足：</p>

<ul>
	<li>数组被分成三个 <strong>非空</strong>&nbsp;连续子数组，从左至右分别命名为&nbsp;<code>left</code>&nbsp;，&nbsp;<code>mid</code>&nbsp;，&nbsp;<code>right</code>&nbsp;。</li>
	<li><code>left</code>&nbsp;中元素和小于等于&nbsp;<code>mid</code>&nbsp;中元素和，<code>mid</code>&nbsp;中元素和小于等于&nbsp;<code>right</code>&nbsp;中元素和。</li>
</ul>

<p>给你一个 <strong>非负</strong> 整数数组&nbsp;<code>nums</code>&nbsp;，请你返回&nbsp;<strong>好的</strong> 分割 <code>nums</code>&nbsp;方案数目。由于答案可能会很大，请你将结果对 <code>10<sup>9&nbsp;</sup>+ 7</code>&nbsp;取余后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,1,1]
<b>输出：</b>1
<b>解释：</b>唯一一种好的分割方案是将 nums 分成 [1] [1] [1] 。</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,2,2,2,5,0]
<b>输出：</b>3
<b>解释：</b>nums 总共有 3 种好的分割方案：
[1] [2] [2,2,5,0]
[1] [2,2] [2,5,0]
[1,2] [2,2] [5,0]
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [3,2,1]
<b>输出：</b>0
<b>解释：</b>没有好的分割方案。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>
</div>

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/ways-to-split-array-into-three-subarrays/solution/ways-to-split-array-by-ikaruga-7whk/)

### 答题
``` C++
class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        const int mod = 1e9 + 7;
        int ans = 0;

        vector<int> pre(1, 0);
        partial_sum(nums.begin(), nums.end(), back_inserter(pre));

        for (int i = 1; i + 2 <= nums.size(); i++) {
            int left = lower_bound(pre, 2 * pre[i]);
            int right = upper_bound(pre, (pre.back() + pre[i]) / 2);
            left = max(left, i + 1);
            right = min(right, (int)nums.size());
            ans += max(0, right - left);
            ans %= mod;
        }

        return ans;
    }

    int lower_bound(vector<int>& pre, int target) {
        int low = 0;
        int high = pre.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (pre[mid] >= target) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }

    int upper_bound(vector<int>& pre, int target) {
        return lower_bound(pre, target + 1);
    }
};
```


### 其它
``` C++
class Solution2 {
public:
    int waysToSplit(vector<int>& nums) {
        const int mod = 1e9 + 7;
        int ans = 0;

        vector<int> pre(1, 0);
        partial_sum(nums.begin(), nums.end(), back_inserter(pre));

        for (int i = 1; i + 2 <= nums.size(); i++) {
            int left = lower_bound(pre.begin(), pre.end(), 2 * pre[i]) - pre.begin();
            int right = upper_bound(pre.begin(), pre.end(), (pre.back() + pre[i]) / 2) - pre.begin();
            left = max(left, i + 1);
            right = min(right, (int)nums.size());
            ans += max(0, right - left);
            ans %= mod;
        }

        return ans;
    }
};
```


