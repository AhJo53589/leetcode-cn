# `（简单）` [665.non-decreasing-array 非递减数列](https://leetcode-cn.com/problems/non-decreasing-array/)

### 题目描述
<p>给你一个长度为&nbsp;<code>n</code>&nbsp;的整数数组，请你判断在 <strong>最多 </strong>改变&nbsp;<code>1</code> 个元素的情况下，该数组能否变成一个非递减数列。</p>

<p>我们是这样定义一个非递减数列的：&nbsp;对于数组中所有的&nbsp;<code>i</code> <code>(0 &lt;= i &lt;= n-2)</code>，总满足 <code>nums[i] &lt;= nums[i + 1]</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> nums = [4,2,3]
<strong>输出:</strong> true
<strong>解释:</strong> 你可以通过把第一个4变成1来使得它成为一个非递减数列。
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> nums = [4,2,1]
<strong>输出:</strong> false
<strong>解释:</strong> 你不能在只改变一个元素的情况下将其变为非递减数列。
</pre>

<p>&nbsp;</p>

<p><strong>说明：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10 ^ 4</code></li>
	<li><code>- 10 ^ 5&nbsp;&lt;= nums[i] &lt;= 10 ^ 5</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                if (i > 1 && nums[i - 2] > nums[i]) {
                    nums[i] = nums[i - 1];
                }
                else {
                    nums[i - 1] = nums[i];
                }
                cnt++;
            }
        }
        return cnt < 2;
    }
};
```




