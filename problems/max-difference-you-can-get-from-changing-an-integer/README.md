# `（中等）` [1432.max-difference-you-can-get-from-changing-an-integer 改变一个整数能得到的最大差值](https://leetcode-cn.com/problems/max-difference-you-can-get-from-changing-an-integer/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-25/problems/max-difference-you-can-get-from-changing-an-integer/)

### 题目描述
<p>给你一个整数&nbsp;<code>num</code>&nbsp;。你可以对它进行如下步骤恰好 <strong>两次</strong>&nbsp;：</p>

<ul>
	<li>选择一个数字&nbsp;<code>x (0&nbsp;&lt;= x &lt;= 9)</code>.</li>
	<li>选择另一个数字&nbsp;<code>y (0&nbsp;&lt;= y &lt;= 9)</code>&nbsp;。数字&nbsp;<code>y</code>&nbsp;可以等于&nbsp;<code>x</code>&nbsp;。</li>
	<li>将 <code>num</code>&nbsp;中所有出现 <code>x</code>&nbsp;的数位都用 <code>y</code>&nbsp;替换。</li>
	<li>得到的新的整数 <strong>不能</strong>&nbsp;有前导 0 ，得到的新整数也 <strong>不能</strong>&nbsp;是 0&nbsp;。</li>
</ul>

<p>令两次对 <code>num</code>&nbsp;的操作得到的结果分别为&nbsp;<code>a</code>&nbsp;和&nbsp;<code>b</code>&nbsp;。</p>

<p>请你返回&nbsp;<code>a</code> 和&nbsp;<code>b</code>&nbsp;的 <strong>最大差值</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>num = 555
<strong>输出：</strong>888
<strong>解释：</strong>第一次选择 x = 5 且 y = 9 ，并把得到的新数字保存在 a 中。
第二次选择 x = 5 且 y = 1 ，并把得到的新数字保存在 b 中。
现在，我们有 a = 999 和 b = 111 ，最大差值为 888
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>num = 9
<strong>输出：</strong>8
<strong>解释：</strong>第一次选择 x = 9 且 y = 9 ，并把得到的新数字保存在 a 中。
第二次选择 x = 9 且 y = 1 ，并把得到的新数字保存在 b 中。
现在，我们有 a = 9 和 b = 1 ，最大差值为 8
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>num = 123456
<strong>输出：</strong>820000
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>num = 10000
<strong>输出：</strong>80000
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>num = 9288
<strong>输出：</strong>8700
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 10^8</code></li>
</ul>

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int maxDiff(int num) {
        string n = to_string(num);
        return getA(n) - getB(n);
    }

    int getA(string n) {
        char t = ' ';
        for (int i = 0; i < n.size(); i++) {
            if (n[i] == '9') continue;
            t = (t == ' ') ? n[i] : t;
            if (n[i] != t) continue;
            n[i] = '9';
        }
        return stoi(n);
    }

    int getB(string n) {
        char t = ' ';
        char exclue = ' ';
        char change = ' ';
        for (int i = 0; i < n.size(); i++) {
            if (i == 0) {
                if (n[i] == '1') {
                    exclue = '1';
                    continue;
                }
                t = n[i];
                change = '1';
                n[i] = change;
                continue;
            }
            if (n[i] == '0' || n[i] == exclue) continue;
            t = (t == ' ') ? n[i] : t;
            if (n[i] != t) continue;
            change = (change == ' ') ? '0' : change;
            n[i] = change;
        }
        return stoi(n);
    }
};
```




