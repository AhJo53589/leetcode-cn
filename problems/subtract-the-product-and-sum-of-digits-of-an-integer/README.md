# `（简单）` [5279.subtract-the-product-and-sum-of-digits-of-an-integer 整数的各位积和之差](https://leetcode-cn.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/)

[contest](https://leetcode-cn.com/contest/weekly-contest-166/problems/subtract-the-product-and-sum-of-digits-of-an-integer/)

### 题目描述
<p>给你一个整数&nbsp;<code>n</code>，请你帮忙计算并返回该整数「各位数字之积」与「各位数字之和」的差。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 234
<strong>输出：</strong>15 
<strong>解释：</strong>
各位数之积 = 2 * 3 * 4 = 24 
各位数之和 = 2 + 3 + 4 = 9 
结果 = 24 - 9 = 15
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 4421
<strong>输出：</strong>21
<strong>解释： 
</strong>各位数之积 = 4 * 4 * 2 * 1 = 32 
各位数之和 = 4 + 4 + 2 + 1 = 11 
结果 = 32 - 11 = 21
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10^5</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
int subtractProductAndSum(int n) 
{
    string num = to_string(n);
    int a = 1;
    int b = 0;
    for (auto i = 0; i < num.size(); i++)
    {
        a *= num[i] - '0';
        b += num[i] - '0';
    }
    return a - b;
}
```




