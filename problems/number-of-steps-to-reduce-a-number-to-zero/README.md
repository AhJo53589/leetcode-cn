# `（简单）` [5311.number-of-steps-to-reduce-a-number-to-zero 将数字变成 0 的操作次数](https://leetcode-cn.com/problems/number-of-steps-to-reduce-a-number-to-zero/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-19/problems/number-of-steps-to-reduce-a-number-to-zero/)

### 题目描述
<p>给你一个非负整数&nbsp;<code>num</code>&nbsp;，请你返回将它变成 0 所需要的步数。 如果当前数字是偶数，你需要把它除以 2 ；否则，减去 1 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>num = 14
<strong>输出：</strong>6
<strong>解释：
</strong>步骤 1) 14 是偶数，除以 2 得到 7 。
步骤 2） 7 是奇数，减 1 得到 6 。
步骤 3） 6 是偶数，除以 2 得到 3 。
步骤 4） 3 是奇数，减 1 得到 2 。
步骤 5） 2 是偶数，除以 2 得到 1 。
步骤 6） 1 是奇数，减 1 得到 0 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>num = 8
<strong>输出：</strong>4
<strong>解释：</strong>
步骤 1） 8 是偶数，除以 2 得到 4 。
步骤 2） 4 是偶数，除以 2 得到 2 。
步骤 3） 2 是偶数，除以 2 得到 1 。
步骤 4） 1 是奇数，减 1 得到 0 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>num = 123
<strong>输出：</strong>12
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= num &lt;= 10^6</code></li>
</ul>

---
### 思路
```
```



### 答题
``` C++
int numberOfSteps (int num)
{
    int ans = 0;
    while (num != 0)
    {
        num = (num % 2 == 0) ? num / 2 : num - 1;
        ans++;
    }
    return ans;
}
```




