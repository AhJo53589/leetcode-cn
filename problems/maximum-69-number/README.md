# `（简单）` [1323.maximum-69-number 6 和 9 组成的最大数字](https://leetcode-cn.com/problems/maximum-69-number/)

[contest](https://leetcode-cn.com/contest/weekly-contest-172/problems/maximum-69-number/)

### 题目描述
<p>给你一个仅由数字 6 和 9 组成的正整数&nbsp;<code>num</code>。</p>

<p>你最多只能翻转一位数字，将 6 变成&nbsp;9，或者把&nbsp;9 变成&nbsp;6 。</p>

<p>请返回你可以得到的最大数字。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>num = 9669
<strong>输出：</strong>9969
<strong>解释：</strong>
改变第一位数字可以得到 6669 。
改变第二位数字可以得到 9969 。
改变第三位数字可以得到 9699 。
改变第四位数字可以得到 9666 。
其中最大的数字是 9969 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>num = 9996
<strong>输出：</strong>9999
<strong>解释：</strong>将最后一位从 6 变到 9，其结果 9999 是最大的数。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>num = 9999
<strong>输出：</strong>9999
<strong>解释：</strong>无需改变就已经是最大的数字了。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 10^4</code></li>
	<li><code>num</code>&nbsp;每一位上的数字都是 6 或者&nbsp;9 。</li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
int maximum69Number (int num) {
    string n = to_string(num);
    for (size_t i = 0; i < n.size(); i++)
    {
        if (n[i] == '9') continue;
        n[i] = '9';
        break;
    }
    return stoi(n);
}
```




