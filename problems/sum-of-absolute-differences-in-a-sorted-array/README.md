# `（中等）` [1685.sum-of-absolute-differences-in-a-sorted-array 有序数组中差绝对值之和](https://leetcode-cn.com/problems/sum-of-absolute-differences-in-a-sorted-array/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-41/problems/sum-of-absolute-differences-in-a-sorted-array/)

### 题目描述
<p>给你一个 <strong>非递减&nbsp;</strong>有序整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>请你建立并返回一个整数数组<em>&nbsp;</em><code>result</code>，它跟<em>&nbsp;</em><code>nums</code>&nbsp;长度相同，且<code>result[i]</code>&nbsp;等于<em>&nbsp;</em><code>nums[i]</code>&nbsp;与数组中所有其他元素差的绝对值之和。</p>

<p>换句话说，&nbsp;<code>result[i]</code>&nbsp;等于&nbsp;<code>sum(|nums[i]-nums[j]|)</code> ，其中&nbsp;<code>0 &lt;= j &lt; nums.length</code> 且&nbsp;<code>j != i</code>&nbsp;（下标从 0 开始）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [2,3,5]
<b>输出：</b>[4,3,5]
<b>解释：</b>假设数组下标从 0 开始，那么
result[0] = |2-2| + |2-3| + |2-5| = 0 + 1 + 3 = 4，
result[1] = |3-2| + |3-3| + |3-5| = 1 + 0 + 2 = 3，
result[2] = |5-2| + |5-3| + |5-5| = 3 + 2 + 0 = 5。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,4,6,8,10]
<b>输出：</b>[24,15,13,15,21]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= nums[i + 1] &lt;= 10<sup>4</sup></code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/sum-of-absolute-differences-in-a-sorted-array/solution/sum-of-absolute-differences-by-ikaruga-ooyv/)

### 答题
``` C++
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> ps(1, 0);
        partial_sum(nums.begin(), nums.end(), back_inserter(ps));

        vector<int> ans(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = ps.back() + (i - (nums.size() - i)) * nums[i] - ps[i] * 2;
        }
        return ans;
    }
};
```




