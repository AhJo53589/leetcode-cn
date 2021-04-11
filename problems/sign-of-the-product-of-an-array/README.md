# `（简单）` [5726.sign-of-the-product-of-an-array 数组元素积的符号](https://leetcode-cn.com/problems/sign-of-the-product-of-an-array/)

[contest](https://leetcode-cn.com/contest/weekly-contest-236/problems/sign-of-the-product-of-an-array/)

### 题目描述
<div class="notranslate"><p>已知函数&nbsp;<code>signFunc(x)</code> 将会根据 <code>x</code> 的正负返回特定值：</p>

<ul>
	<li>如果 <code>x</code> 是正数，返回 <code>1</code> 。</li>
	<li>如果 <code>x</code> 是负数，返回 <code>-1</code> 。</li>
	<li>如果 <code>x</code> 是等于 <code>0</code> ，返回 <code>0</code> 。</li>
</ul>

<p>给你一个整数数组 <code>nums</code> 。令 <code>product</code> 为数组 <code>nums</code> 中所有元素值的乘积。</p>

<p>返回 <code>signFunc(product)</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [-1,-2,-3,-4,3,2,1]
<strong>输出：</strong>1
<strong>解释：</strong>数组中所有值的乘积是 144 ，且 signFunc(144) = 1
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,5,0,2,-3]
<strong>输出：</strong>0
<strong>解释：</strong>数组中所有值的乘积是 0 ，且 signFunc(0) = 0
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [-1,1,-1,1,-1]
<strong>输出：</strong>-1
<strong>解释：</strong>数组中所有值的乘积是 -1 ，且 signFunc(-1) = -1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>-100 &lt;= nums[i] &lt;= 100</code></li>
</ul>
</div>

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/sign-of-the-product-of-an-array/solution/sign-of-the-product-of-an-array-by-ikaru-mxyo/)

### 答题
``` C++
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for (auto n : nums) {
            if (n == 0) return 0;
            ans *= (n > 0) ? 1 : -1;
        }
        return ans;
    }
};
```




