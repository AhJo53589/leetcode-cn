# `（困难）` [1406.stone-game-iii 石子游戏 III](https://leetcode-cn.com/problems/stone-game-iii/)

[contest](https://leetcode-cn.com/contest/weekly-contest-183/problems/stone-game-iii/)

### 题目描述
<p>Alice 和 Bob 用几堆石子在做游戏。几堆石子排成一行，每堆石子都对应一个得分，由数组 <code>stoneValue</code> 给出。</p>

<p>Alice 和 Bob 轮流取石子，<strong>Alice</strong> 总是先开始。在每个玩家的回合中，该玩家可以拿走剩下石子中的的前 <strong>1、2 或 3 堆石子</strong> 。比赛一直持续到所有石头都被拿走。</p>

<p>每个玩家的最终得分为他所拿到的每堆石子的对应得分之和。每个玩家的初始分数都是 <strong>0</strong> 。比赛的目标是决出最高分，得分最高的选手将会赢得比赛，比赛也可能会出现平局。</p>

<p>假设 Alice 和 Bob 都采取 <strong>最优策略</strong> 。如果 Alice 赢了就返回 <em>"Alice"</em> <em>，</em>Bob 赢了就返回<em> "Bob"，</em>平局（分数相同）返回 <em>"Tie"</em> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>values = [1,2,3,7]
<strong>输出：</strong>"Bob"
<strong>解释：</strong>Alice 总是会输，她的最佳选择是拿走前三堆，得分变成 6 。但是 Bob 的得分为 7，Bob 获胜。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>values = [1,2,3,-9]
<strong>输出：</strong>"Alice"
<strong>解释：</strong>Alice 要想获胜就必须在第一个回合拿走前三堆石子，给 Bob 留下负分。
如果 Alice 只拿走第一堆，那么她的得分为 1，接下来 Bob 拿走第二、三堆，得分为 5 。之后 Alice 只能拿到分数 -9 的石子堆，输掉比赛。
如果 Alice 拿走前两堆，那么她的得分为 3，接下来 Bob 拿走第三堆，得分为 3 。之后 Alice 只能拿到分数 -9 的石子堆，同样会输掉比赛。
注意，他们都应该采取 <strong>最优策略 </strong>，所以在这里 Alice 将选择能够使她获胜的方案。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>values = [1,2,3,6]
<strong>输出：</strong>"Tie"
<strong>解释：</strong>Alice 无法赢得比赛。如果她决定选择前三堆，她可以以平局结束比赛，否则她就会输。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>values = [1,2,3,-1,-2,-3,7]
<strong>输出：</strong>"Alice"
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>values = [-1,-2,-3]
<strong>输出：</strong>"Tie"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= values.length &lt;= 50000</code></li>
	<li><code>-1000&nbsp;&lt;= values[i] &lt;= 1000</code></li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
    string stoneGameIII(vector<int>& stoneValue)
    {
        vector<int> dp(stoneValue.size(), INT_MIN);
        for (int i = stoneValue.size() - 1; i >= 0; i--)
        {
            int s = 0;
            for (int j = 0; j < 3 && i + j + 1 <= stoneValue.size(); j++)
            {
                s += stoneValue[i + j];
                dp[i] = (i + j + 1 == stoneValue.size()) ? max(dp[i], s) : dp[i] = max(dp[i], s - dp[i + j + 1]);
            }
        }

        if (dp[0] == 0) return "Tie";
        return (dp[0] > 0) ? "Alice" : "Bob";
    }
```




