# `（简单）` [5830.three-divisors 三除数](https://leetcode-cn.com/problems/three-divisors/)

[contest](https://leetcode-cn.com/contest/weekly-contest-252/problems/three-divisors/)

### 题目描述
<div class="notranslate"><p>给你一个整数 <code>n</code> 。如果 <code>n</code> <strong>恰好有三个正除数</strong> ，返回 <code>true</code><em> </em>；否则，返回<em> </em><code>false</code> 。</p>

<p>如果存在整数 <code>k</code> ，满足 <code>n = k * m</code> ，那么整数 <code>m</code> 就是 <code>n</code> 的一个 <strong>除数</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 2
<strong>输出：</strong>false
<strong>解释：</strong>2 只有两个除数：1 和 2 。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 4
<strong>输出：</strong>true
<strong>解释：</strong>4 有三个除数：1、2 和 4 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
</ul>
</div>

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    bool isThree(int n) {
        int ans = 0;
        for (int i = 2; i < n; i++) {
            ans += (n % i == 0);
        }
        return ans == 1;
    }
};
```




