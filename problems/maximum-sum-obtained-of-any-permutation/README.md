# `（中等）` [5505.maximum-sum-obtained-of-any-permutation 所有排列中的最大和](https://leetcode-cn.com/problems/maximum-sum-obtained-of-any-permutation/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-35/problems/maximum-sum-obtained-of-any-permutation/)

### 题目描述
<p>有一个整数数组&nbsp;<code>nums</code>&nbsp;，和一个查询数组&nbsp;<code>requests</code>&nbsp;，其中&nbsp;<code>requests[i] = [start<sub>i</sub>, end<sub>i</sub>]</code>&nbsp;。第&nbsp;<code>i</code>&nbsp;个查询求&nbsp;<code>nums[start<sub>i</sub>] + nums[start<sub>i</sub> + 1] + ... + nums[end<sub>i</sub> - 1] + nums[end<sub>i</sub>]</code>&nbsp;的结果&nbsp;，<code>start<sub>i</sub></code> 和&nbsp;<code>end<sub>i</sub></code>&nbsp;数组索引都是 <strong>从 0 开始</strong> 的。</p>

<p>你可以任意排列 <code>nums</code>&nbsp;中的数字，请你返回所有查询结果之和的最大值。</p>

<p>由于答案可能会很大，请你将它对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3,4,5], requests = [[1,3],[0,1]]
<strong>输出：</strong>19
<strong>解释：</strong>一个可行的 nums 排列为 [2,1,3,4,5]，并有如下结果：
requests[0] -> nums[1] + nums[2] + nums[3] = 1 + 3 + 4 = 8
requests[1] -> nums[0] + nums[1] = 2 + 1 = 3
总和为：8 + 3 = 11。
一个总和更大的排列为 [3,5,4,2,1]，并有如下结果：
requests[0] -> nums[1] + nums[2] + nums[3] = 5 + 4 + 2 = 11
requests[1] -> nums[0] + nums[1] = 3 + 5  = 8
总和为： 11 + 8 = 19，这个方案是所有排列中查询之和最大的结果。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3,4,5,6], requests = [[0,1]]
<strong>输出：</strong>11
<strong>解释：</strong>一个总和最大的排列为 [6,5,4,3,2,1] ，查询和为 [11]。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3,4,5,10], requests = [[0,2],[1,3],[1,1]]
<strong>输出：</strong>47
<strong>解释：</strong>一个和最大的排列为 [4,10,5,3,2,1] ，查询结果分别为 [19,18,10]。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 <= n <= 10<sup>5</sup></code></li>
	<li><code>0 <= nums[i]&nbsp;<= 10<sup>5</sup></code></li>
	<li><code>1 <= requests.length <=&nbsp;10<sup>5</sup></code></li>
	<li><code>requests[i].length == 2</code></li>
	<li><code>0 <= start<sub>i</sub>&nbsp;<= end<sub>i</sub>&nbsp;<&nbsp;n</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        vector<int> cnt(nums.size() + 1, 0);
        for (int i = 0; i < requests.size(); i++) {
            cnt[requests[i][0]]++;
            cnt[requests[i][1] + 1]--;
        }
        for (int i = 1; i < cnt.size(); i++) {
            cnt[i] += cnt[i - 1];
        }

        sort(nums.rbegin(), nums.rend());
        sort(cnt.rbegin(), cnt.rend());
        const int mod = 1e9 + 7;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += (nums[i] * cnt[i]) % mod;
            ans %= mod;
        }

        return ans;
    }
```




