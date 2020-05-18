# `（困难）` [1449.form-largest-integer-with-digits-that-add-up-to-target 数位成本和为目标值的最大数字](https://leetcode-cn.com/problems/form-largest-integer-with-digits-that-add-up-to-target/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-26/problems/form-largest-integer-with-digits-that-add-up-to-target/)

### 题目描述
<p>给你一个整数数组&nbsp;<code>cost</code>&nbsp;和一个整数&nbsp;<code>target</code>&nbsp;。请你返回满足如下规则可以得到的&nbsp;<strong>最大</strong>&nbsp;整数：</p>

<ul>
	<li>给当前结果添加一个数位（<code>i + 1</code>）的成本为&nbsp;<code>cost[i]</code>&nbsp;（<code>cost</code>&nbsp;数组下标从 0 开始）。</li>
	<li>总成本必须恰好等于&nbsp;<code>target</code>&nbsp;。</li>
	<li>添加的数位中没有数字 0 。</li>
</ul>

<p>由于答案可能会很大，请你以字符串形式返回。</p>

<p>如果按照上述要求无法得到任何整数，请你返回 "0" 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>cost = [4,3,2,5,6,7,2,5,5], target = 9
<strong>输出：</strong>"7772"
<strong>解释：</strong>添加数位 '7' 的成本为 2 ，添加数位 '2' 的成本为 3 。所以 "7772" 的代价为 2*3+ 3*1 = 9 。 "997" 也是满足要求的数字，但 "7772" 是较大的数字。
<strong> 数字     成本</strong>
  1  -&gt;   4
  2  -&gt;   3
  3  -&gt;   2
  4  -&gt;   5
  5  -&gt;   6
  6  -&gt;   7
  7  -&gt;   2
  8  -&gt;   5
  9  -&gt;   5
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>cost = [7,6,5,5,5,6,8,7,8], target = 12
<strong>输出：</strong>"85"
<strong>解释：</strong>添加数位 '8' 的成本是 7 ，添加数位 '5' 的成本是 5 。"85" 的成本为 7 + 5 = 12 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>cost = [2,4,6,2,4,6,4,4,4], target = 5
<strong>输出：</strong>"0"
<strong>解释：</strong>总成本是 target 的条件下，无法生成任何整数。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>cost = [6,10,15,40,40,40,40,40,40], target = 47
<strong>输出：</strong>"32211"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>cost.length == 9</code></li>
	<li><code>1 &lt;= cost[i] &lt;= 5000</code></li>
	<li><code>1 &lt;= target &lt;= 5000</code></li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<string>dp(target + 1);
        dp[0] = "";
        for (int j = 1; j <= target; j++) {
            dp[j] = "0";
        }
        for (int i = 0; i < cost.size(); i++) {
            for (int j = cost[i]; j <= target; j++) {
                dp[j] = mmin(dp[j], add(dp[j - cost[i]], i + 1));
            }
        }
        return dp[target];
    }

    string mmin(string a, string b) {
        if (a.size() > b.size()) return a;
        else if (b.size() > a.size()) return b;
        return a > b ? a : b;
    }

    string add(string a, int b) {
        if (a == "0") return "0";
        string c = to_string(b);
        return c + a;
    }
};
```




