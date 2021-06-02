# `（简单）` [1716.calculate-money-in-leetcode-bank 计算力扣银行的钱](https://leetcode-cn.com/problems/calculate-money-in-leetcode-bank/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-43/problems/calculate-money-in-leetcode-bank/)

### 题目描述
<p>Hercy 想要为购买第一辆车存钱。他 <strong>每天</strong> 都往力扣银行里存钱。</p>

<p>最开始，他在周一的时候存入 <code>1</code>&nbsp;块钱。从周二到周日，他每天都比前一天多存入 <code>1</code>&nbsp;块钱。在接下来每一个周一，他都会比 <strong>前一个周一</strong> 多存入 <code>1</code>&nbsp;块钱。<span style=""> </span></p>

<p>给你&nbsp;<code>n</code>&nbsp;，请你返回在第 <code>n</code>&nbsp;天结束的时候他在力扣银行总共存了多少块钱。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>n = 4
<b>输出：</b>10
<b>解释：</b>第 4 天后，总额为 1 + 2 + 3 + 4 = 10 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>n = 10
<b>输出：</b>37
<b>解释：</b>第 10 天后，总额为 (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4) = 37 。注意到第二个星期一，Hercy 存入 2 块钱。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>n = 20
<b>输出：</b>96
<b>解释：</b>第 20 天后，总额为 (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4 + 5 + 6 + 7 + 8) + (3 + 4 + 5 + 6 + 7 + 8) = 96 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int totalMoney(int n) {
        vector<int> m = { 1, 2, 3, 4, 5, 6, 7 };
        vector<int> mm(1, 0);
        partial_sum(m.begin(), m.end(), back_inserter(mm));

        int ans = 0;
        int wk = n / 7;
        ans += wk * mm.back();
        ans += (1 + wk - 1) * (wk - 1) / 2 * 7;

        int d = n % 7;
        ans += mm[d] + d * wk;
        return ans;
    }
};
```




