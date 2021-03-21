# `（困难）` [5696.count-pairs-with-xor-in-a-range 统计异或值在范围内的数对有多少](https://leetcode-cn.com/problems/count-pairs-with-xor-in-a-range/)

[contest](https://leetcode-cn.com/contest/weekly-contest-233/problems/count-pairs-with-xor-in-a-range/)

### 题目描述
<p>给你一个整数数组 <code>nums</code> （下标 <strong>从 0 开始</strong> 计数）以及两个整数：<code>low</code> 和 <code>high</code> ，请返回 <strong>漂亮数对</strong> 的数目。</p>

<p><strong>漂亮数对</strong> 是一个形如 <code>(i, j)</code> 的数对，其中 <code>0 &lt;= i &lt; j &lt; nums.length</code> 且 <code>low &lt;= (nums[i] XOR nums[j]) &lt;= high</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,4,2,7], low = 2, high = 6
<strong>输出：</strong>6
<strong>解释：</strong>所有漂亮数对 (i, j) 列出如下：
    - (0, 1): nums[0] XOR nums[1] = 5 
    - (0, 2): nums[0] XOR nums[2] = 3
    - (0, 3): nums[0] XOR nums[3] = 6
    - (1, 2): nums[1] XOR nums[2] = 6
    - (1, 3): nums[1] XOR nums[3] = 3
    - (2, 3): nums[2] XOR nums[3] = 5
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [9,8,4,2,1], low = 5, high = 14
<strong>输出：</strong>8
<strong>解释：</strong>所有漂亮数对 (i, j) 列出如下：
​​​​​    - (0, 2): nums[0] XOR nums[2] = 13
&nbsp;   - (0, 3): nums[0] XOR nums[3] = 11
&nbsp;   - (0, 4): nums[0] XOR nums[4] = 8
&nbsp;   - (1, 2): nums[1] XOR nums[2] = 12
&nbsp;   - (1, 3): nums[1] XOR nums[3] = 10
&nbsp;   - (1, 4): nums[1] XOR nums[4] = 9
&nbsp;   - (2, 3): nums[2] XOR nums[3] = 6
&nbsp;   - (2, 4): nums[2] XOR nums[4] = 5</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= low &lt;= high &lt;= 2 * 10<sup>4</sup></code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {

    }
};
```




