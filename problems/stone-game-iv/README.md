# `（困难）` [1510.stone-game-iv 石子游戏 IV](https://leetcode-cn.com/problems/stone-game-iv/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-30/problems/stone-game-iv/)

### 题目描述
<p>Alice 和 Bob 两个人轮流玩一个游戏，Alice 先手。</p>

<p>一开始，有 <code>n</code>&nbsp;个石子堆在一起。每个人轮流操作，正在操作的玩家可以从石子堆里拿走 <strong>任意</strong>&nbsp;非零 <strong>平方数</strong>&nbsp;个石子。</p>

<p>如果石子堆里没有石子了，则无法操作的玩家输掉游戏。</p>

<p>给你正整数&nbsp;<code>n</code>&nbsp;，且已知两个人都采取最优策略。如果 Alice 会赢得比赛，那么返回&nbsp;<code>True</code>&nbsp;，否则返回&nbsp;<code>False</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 1
<strong>输出：</strong>true
<strong>解释：</strong>Alice 拿走 1 个石子并赢得胜利，因为 Bob 无法进行任何操作。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 2
<strong>输出：</strong>false
<strong>解释：</strong>Alice 只能拿走 1 个石子，然后 Bob 拿走最后一个石子并赢得胜利（2 -> 1 -> 0）。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 4
<strong>输出：</strong>true
<strong>解释：</strong>n 已经是一个平方数，Alice 可以一次全拿掉 4 个石子并赢得胜利（4 -> 0）。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>n = 7
<strong>输出：</strong>false
<strong>解释：</strong>当 Bob 采取最优策略时，Alice 无法赢得比赛。
如果 Alice 一开始拿走 4 个石子， Bob 会拿走 1 个石子，然后 Alice 只能拿走 1 个石子，Bob 拿走最后一个石子并赢得胜利（7 -> 3 -> 2 -> 1 -> 0）。
如果 Alice 一开始拿走 1 个石子， Bob 会拿走 4 个石子，然后 Alice 只能拿走 1 个石子，Bob 拿走最后一个石子并赢得胜利（7 -> 6 -> 2 -> 1 -> 0）。</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>n = 17
<strong>输出：</strong>false
<strong>解释：</strong>如果 Bob 采取最优策略，Alice 无法赢得胜利。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 10^5</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/stone-game-iv/solution/stone-game-iv-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    bool winnerSquareGame(int n) {
        return dfs(n);
    }

    bool dfs(int n) {
        if (n == 0) return false;
        if (n == 1) return true;
        if (dp.count(n) != 0) return dp[n];
        int i = 1;
        while (i * i <= n) {
            if (!dfs(n - i * i)) {
                dp[n] = true;
                return true;
            }
            i++;
        }
        dp[n] = false;
        return false;
    }

private:
    unordered_map<int, bool> dp;
};
```




