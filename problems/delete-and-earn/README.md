# `（中等）` [740.delete-and-earn 删除并获得点数](https://leetcode-cn.com/problems/delete-and-earn/)

### 题目描述
<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;，你可以对它进行一些操作。</p>

<p>每次操作中，选择任意一个&nbsp;<code>nums[i]</code>&nbsp;，删除它并获得&nbsp;<code>nums[i]</code>&nbsp;的点数。之后，你必须删除<strong>每个</strong>等于&nbsp;<code>nums[i] - 1</code>&nbsp;或&nbsp;<code>nums[i] + 1</code>&nbsp;的元素。</p>

<p>开始你拥有 <code>0</code> 个点数。返回你能通过这些操作获得的最大点数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [3,4,2]
<strong>输出：</strong>6
<strong>解释：</strong>
删除 4 获得 4 个点数，因此 3 也被删除。
之后，删除 2 获得 2 个点数。总共获得 6 个点数。
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre><strong>输入：</strong>nums = [2,2,3,3,3,4]
<strong>输出：</strong>9
<strong>解释：</strong>
删除 3 获得 3 个点数，接着要删除两个 2 和 4 。
之后，再次删除 3 获得 3 个点数，再次删除 3 获得 3 个点数。
总共获得 9 个点数。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> sum(maxVal + 2, 0);
        for (auto& n : nums) {
            sum[n] += n;
        }

        int first = 0;
        int second = sum[1];
        for (int i = 2; i < sum.size(); i++) {
            int temp = max(second, first + sum[i]);
            first = second;
            second = temp;
        }
        return second;
    }
};
```




