# `（困难）` [5766.stone-game-viii 石子游戏 VIII](https://leetcode-cn.com/problems/stone-game-viii/)

[contest](https://leetcode-cn.com/contest/weekly-contest-242/problems/stone-game-viii/)

### 题目描述
<div class="notranslate"><p>Alice 和 Bob 玩一个游戏，两人轮流操作， <strong>Alice 先手</strong>&nbsp;。</p>

<p>总共有&nbsp;<code>n</code>&nbsp;个石子排成一行。轮到某个玩家的回合时，如果石子的数目 <strong>大于 1</strong>&nbsp;，他将执行以下操作：</p>

<ol>
	<li>选择一个整数&nbsp;<code>x &gt; 1</code>&nbsp;，并且 <strong>移除</strong>&nbsp;最左边的&nbsp;<code>x</code>&nbsp;个石子。</li>
	<li>将<strong>&nbsp;移除</strong>&nbsp;的石子价值之 <strong>和</strong>&nbsp;累加到该玩家的分数中。</li>
	<li>将一个 <strong>新的石子</strong>&nbsp;放在最左边，且新石子的值为被移除石子值之和。</li>
</ol>

<p>当只剩下 <strong>一个</strong>&nbsp;石子时，游戏结束。</p>

<p>Alice 和 Bob 的 <strong>分数之差</strong>&nbsp;为&nbsp;<code>(Alice 的分数&nbsp;- Bob 的分数)</code>&nbsp;。&nbsp;Alice 的目标是<strong>&nbsp;最大化</strong>&nbsp;分数差，Bob 的目标是 <strong>最小化</strong>&nbsp;分数差。</p>

<p>给你一个长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>stones</code>&nbsp;，其中&nbsp;<code>stones[i]</code>&nbsp;是 <strong>从左边起</strong>&nbsp;第&nbsp;<code>i</code>&nbsp;个石子的价值。请你返回在双方都采用 <strong>最优</strong> 策略的情况下，Alice 和 Bob 的 <strong>分数之差</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>stones = [-1,2,-3,4,-5]
<b>输出：</b>5
<strong>解释：</strong>
- Alice 移除最左边的 4 个石子，得分增加 (-1) + 2 + (-3) + 4 = 2 ，并且将一个价值为 2 的石子放在最左边。stones = [2,-5] 。
- Bob 移除最左边的 2 个石子，得分增加 2 + (-5) = -3 ，并且将一个价值为 -3 的石子放在最左边。stones = [-3] 。
两者分数之差为 2 - (-3) = 5 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>stones = [7,-6,5,10,5,-2,-6]
<b>输出：</b>13
<b>解释：</b>
- Alice 移除所有石子，得分增加 7 + (-6) + 5 + 10 + 5 + (-2) + (-6) = 13 ，并且将一个价值为 13 的石子放在最左边。stones = [13] 。
两者分数之差为 13 - 0 = 13 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>stones = [-10,-12]
<b>输出：</b>-22
<strong>解释：</strong>
- Alice 只有一种操作，就是移除所有石子。得分增加 (-10) + (-12) = -22 ，并且将一个价值为 -22 的石子放在最左边。stones = [-22] 。
两者分数之差为 (-22) - 0 = -22 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == stones.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= stones[i] &lt;= 10<sup>4</sup></code></li>
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
    int stoneGameVIII(vector<int>& stones) {
        vector<int> ps = { 0 };
        partial_sum(stones.begin(), stones.end(), back_inserter(ps));
        
        vector<int> dp = vector<int>(stones.size(), 0);
        int mx = ps.back();
        for (int i = (int)stones.size() - 1; ~i; i--) {
            dp[i] = mx;
            mx = max(mx, ps[i] - dp[i]);
        }
        return dp[1];
    }
};
```




