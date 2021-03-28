# `（困难）` [5716.maximize-number-of-nice-divisors 好因子的最大数目](https://leetcode-cn.com/problems/maximize-number-of-nice-divisors/)

[contest](https://leetcode-cn.com/contest/weekly-contest-234/problems/maximize-number-of-nice-divisors/)

### 题目描述
<p>给你一个正整数&nbsp;<code>primeFactors</code>&nbsp;。你需要构造一个正整数&nbsp;<code>n</code>&nbsp;，它满足以下条件：</p>

<ul>
	<li><code>n</code>&nbsp;质因数（质因数需要考虑重复的情况）的数目 <strong>不超过&nbsp;</strong><code>primeFactors</code>&nbsp;个。</li>
	<li><code>n</code>&nbsp;好因子的数目最大化。如果 <code>n</code>&nbsp;的一个因子可以被 <code>n</code>&nbsp;的每一个质因数整除，我们称这个因子是 <strong>好因子</strong> 。比方说，如果&nbsp;<code>n = 12</code>&nbsp;，那么它的质因数为&nbsp;<code>[2,2,3]</code>&nbsp;，那么&nbsp;<code>6</code>&nbsp;和&nbsp;<code>12</code>&nbsp;是好因子，但&nbsp;<code>3</code> 和&nbsp;<code>4</code>&nbsp;不是。</li>
</ul>

<p>请你返回&nbsp;<code>n</code>&nbsp;的好因子的数目。由于答案可能会很大，请返回答案对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<b>取余</b>&nbsp;的结果。</p>

<p>请注意，一个质数的定义是大于 <code>1</code>&nbsp;，且不能被分解为两个小于该数的自然数相乘。一个数 <code>n</code>&nbsp;的质因子是将 <code>n</code>&nbsp;分解为若干个质因子，且它们的乘积为 <code>n</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>primeFactors = 5
<strong>输出：</strong>6
<b>解释：</b>200 是一个可行的 n 。
它有 5 个质因子：[2,2,2,5,5] ，且有 6 个好因子：[10,20,40,50,100,200] 。
不存在别的 n 有至多 5 个质因子，且同时有更多的好因子。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>primeFactors = 8
<b>输出：</b>18
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= primeFactors &lt;= 10<sup>9</sup></code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int maxNiceDivisors(int primeFactors) {
        if (primeFactors == 1) return 1;

        long long mod = 1e9 + 7;
        int last = (primeFactors % 3 == 1) ? 4 : (primeFactors % 3 == 2) ? 2 : 0;
        primeFactors -= last;
        int n = primeFactors / 3;

        long long ans = qpow(3, n, mod);
        if (last != 0) {
            ans = qmul(ans, last, mod);
        }
        return ans;
    }

    long long qmul(long long x, long long y, long long mod)
    {
        long long ret = 0;
        while (y) {
            if (y & 1)
                ret = (ret + x) % mod;
            x = x * 2 % mod;
            y >>= 1;
        }
        return ret;
    }

    long long qpow(long long a, long long n, long long mod)
    {
        long long ret = 1;
        while (n)
        {
            if (n & 1) ret = qmul(ret, a, mod);
            a = qmul(a, a, mod);
            n >>= 1;
        }
        return ret;
    }
};
```




