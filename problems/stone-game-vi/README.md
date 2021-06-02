# `（中等）` [1686.stone-game-vi 石子游戏 VI](https://leetcode-cn.com/problems/stone-game-vi/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-41/problems/stone-game-vi/)

### 题目描述
<p>Alice 和&nbsp;Bob 轮流玩一个游戏，Alice 先手。</p>

<p>一堆石子里总共有&nbsp;<code>n</code>&nbsp;个石子，轮到某个玩家时，他可以 <strong>移出</strong>&nbsp;一个石子并得到这个石子的价值。Alice 和 Bob 对石子价值有 <strong>不一样的的评判标准</strong>&nbsp;。双方都知道对方的评判标准。</p>

<p>给你两个长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>aliceValues</code> 和&nbsp;<code>bobValues</code>&nbsp;。<code>aliceValues[i]</code> 和&nbsp;<code>bobValues[i]</code>&nbsp;分别表示 Alice 和 Bob 认为第&nbsp;<code>i</code>&nbsp;个石子的价值。</p>

<p>所有石子都被取完后，得分较高的人为胜者。如果两个玩家得分相同，那么为平局。两位玩家都会采用 <b>最优策略</b>&nbsp;进行游戏。</p>

<p>请你推断游戏的结果，用如下的方式表示：</p>

<ul>
	<li>如果 Alice 赢，返回&nbsp;<code>1</code>&nbsp;。</li>
	<li>如果 Bob 赢，返回&nbsp;<code>-1</code>&nbsp;。</li>
	<li>如果游戏平局，返回&nbsp;<code>0</code>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>aliceValues = [1,3], bobValues = [2,1]
<b>输出：</b>1
<strong>解释：</strong>
如果 Alice 拿石子 1 （下标从 0开始），那么 Alice 可以得到 3 分。
Bob 只能选择石子 0 ，得到 2 分。
Alice 获胜。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>aliceValues = [1,2], bobValues = [3,1]
<b>输出：</b>0
<strong>解释：</strong>
Alice 拿石子 0 ， Bob 拿石子 1 ，他们得分都为 1 分。
打平。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>aliceValues = [2,4,3], bobValues = [1,6,7]
<b>输出：</b>-1
<strong>解释：</strong>
不管 Alice 怎么操作，Bob 都可以得到比 Alice 更高的得分。
比方说，Alice 拿石子 1 ，Bob 拿石子 2 ， Alice 拿石子 0 ，Alice 会得到 6 分而 Bob 得分为 7 分。
Bob 会获胜。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == aliceValues.length == bobValues.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= aliceValues[i], bobValues[i] &lt;= 100</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<pair<int, int>> val(aliceValues.size());
        for (int i = 0; i < val.size(); i++) {
            val[i] = { aliceValues[i] + bobValues[i], i };
        }
        sort(val.rbegin(), val.rend());

        int ans = 0;
        for (int i = 0; i < val.size(); i++) {
            if (i % 2 == 0) {
                ans += aliceValues[val[i].second];
            }
            else {
                ans -= bobValues[val[i].second];
            }
        }
        return ans == 0 ? 0 : abs(ans) / ans;
    }
};
```




