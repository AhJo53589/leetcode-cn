# `（中等）` [5719.maximum-xor-for-each-query 每个查询的最大异或值](https://leetcode-cn.com/problems/maximum-xor-for-each-query/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-50/problems/maximum-xor-for-each-query/)

### 题目描述
<div class="question-content default-content">
              <p>给你一个 <strong>有序</strong>&nbsp;数组&nbsp;<code>nums</code>&nbsp;，它由&nbsp;<code>n</code>&nbsp;个非负整数组成，同时给你一个整数&nbsp;<code>maximumBit</code>&nbsp;。你需要执行以下查询 <code>n</code>&nbsp;次：</p>

<ol>
	<li>找到一个非负整数&nbsp;<code>k &lt; 2<sup>maximumBit</sup></code>&nbsp;，使得&nbsp;<code>nums[0] XOR nums[1] XOR ... XOR nums[nums.length-1] XOR k</code>&nbsp;的结果 <strong>最大化</strong>&nbsp;。<code>k</code>&nbsp;是第 <code>i</code>&nbsp;个查询的答案。</li>
	<li>从当前数组&nbsp;<code>nums</code>&nbsp;删除&nbsp;<strong>最后</strong>&nbsp;一个元素。</li>
</ol>

<p>请你返回一个数组&nbsp;<code>answer</code>&nbsp;，其中<em>&nbsp;</em><code>answer[i]</code>是第&nbsp;<code>i</code>&nbsp;个查询的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [0,1,1,3], maximumBit = 2
<b>输出：</b>[0,3,2,3]
<b>解释：</b>查询的答案如下：
第一个查询：nums = [0,1,1,3]，k = 0，因为 0 XOR 1 XOR 1 XOR 3 XOR 0 = 3 。
第二个查询：nums = [0,1,1]，k = 3，因为 0 XOR 1 XOR 1 XOR 3 = 3 。
第三个查询：nums = [0,1]，k = 2，因为 0 XOR 1 XOR 2 = 3 。
第四个查询：nums = [0]，k = 3，因为 0 XOR 3 = 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [2,3,4,7], maximumBit = 3
<b>输出：</b>[5,2,6,5]
<b>解释：</b>查询的答案如下：
第一个查询：nums = [2,3,4,7]，k = 5，因为 2 XOR 3 XOR 4 XOR 7 XOR 5 = 7。
第二个查询：nums = [2,3,4]，k = 2，因为 2 XOR 3 XOR 4 XOR 2 = 7 。
第三个查询：nums = [2,3]，k = 6，因为 2 XOR 3 XOR 6 = 7 。
第四个查询：nums = [2]，k = 5，因为 2 XOR 5 = 7 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [0,1,2,2,5,7], maximumBit = 3
<b>输出：</b>[4,3,6,4,6,7]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>nums.length == n</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= maximumBit &lt;= 20</code></li>
	<li><code>0 &lt;= nums[i] &lt; 2<sup>maximumBit</sup></code></li>
	<li><code>nums</code>​​​ 中的数字已经按&nbsp;<strong>升序</strong>&nbsp;排好序。</li>
</ul>

            </div>

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int res = pow(2, maximumBit) - 1;
        for (auto n : nums) {
            res ^= n;
        }

        vector<int> ans(nums.size());
        for (int i = 0; i < ans.size(); i++) {
            ans[i] = res;
            res ^= nums[(int)nums.size() - 1 - i];
        }
        return ans;
    }
};
```




