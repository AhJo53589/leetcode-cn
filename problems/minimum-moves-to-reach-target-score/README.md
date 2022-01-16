# `（中等）` [5194.minimum-moves-to-reach-target-score 得到目标值的最少行动次数](https://leetcode-cn.com/problems/minimum-moves-to-reach-target-score/)

[contest](https://leetcode-cn.com/contest/weekly-contest-276/problems/minimum-moves-to-reach-target-score/)

### 题目描述
<div class="notranslate"><p>你正在玩一个整数游戏。从整数 <code>1</code> 开始，期望得到整数 <code>target</code> 。</p>

<p>在一次行动中，你可以做下述两种操作之一：</p>

<ul>
	<li><strong>递增</strong>，将当前整数的值加 1（即， <code>x = x + 1</code>）。</li>
	<li><strong>加倍</strong>，使当前整数的值翻倍（即，<code>x = 2 * x</code>）。</li>
</ul>

<p>在整个游戏过程中，你可以使用 <strong>递增</strong> 操作 <strong>任意</strong> 次数。但是只能使用 <strong>加倍</strong> 操作 <strong>至多</strong> <code>maxDoubles</code> 次。</p>

<p>给你两个整数 <code>target</code> 和 <code>maxDoubles</code> ，返回从 1 开始得到<em> </em><code>target</code><em> </em>需要的最少行动次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>target = 5, maxDoubles = 0
<strong>输出：</strong>4
<strong>解释：</strong>一直递增 1 直到得到 target 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>target = 19, maxDoubles = 2
<strong>输出：</strong>7
<strong>解释：</strong>最初，x = 1 。
递增 3 次，x = 4 。
加倍 1 次，x = 8 。
递增 1 次，x = 9 。
加倍 1 次，x = 18 。
递增 1 次，x = 19 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>target = 10, maxDoubles = 4
<strong>输出：</strong>4
<strong>解释：</strong>
最初，x = 1 。 
递增 1 次，x = 2 。 
加倍 1 次，x = 4 。 
递增 1 次，x = 5 。 
加倍 1 次，x = 10 。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= target &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= maxDoubles &lt;= 100</code></li>
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
    int minMoves(int target, int maxDoubles) {
        int ans = 0;
        while (target != 1 && maxDoubles > 0) {
            ans += target % 2;
            target /= 2;
            maxDoubles--;
            ans++;
        }
        ans += target - 1;
        return ans;
    }
};
```




