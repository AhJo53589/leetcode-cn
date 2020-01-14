# `（简单）` [1025.divisor-game 除数博弈](https://leetcode-cn.com/problems/divisor-game/)

### 题目描述
<p>爱丽丝和鲍勃一起玩游戏，他们轮流行动。爱丽丝先手开局。</p>

<p>最初，黑板上有一个数字&nbsp;<code>N</code>&nbsp;。在每个玩家的回合，玩家需要执行以下操作：</p>

<ul>
	<li>选出任一&nbsp;<code>x</code>，满足&nbsp;<code>0 &lt; x &lt; N</code> 且&nbsp;<code>N % x == 0</code>&nbsp;。</li>
	<li>用 <code>N - x</code>&nbsp;替换黑板上的数字 <code>N</code> 。</li>
</ul>

<p>如果玩家无法执行这些操作，就会输掉游戏。</p>

<p>只有在爱丽丝在游戏中取得胜利时才返回&nbsp;<code>True</code>，否则返回 <code>false</code>。假设两个玩家都以最佳状态参与游戏。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>2
<strong>输出：</strong>true
<strong>解释：</strong>爱丽丝选择 1，鲍勃无法进行操作。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>3
<strong>输出：</strong>false
<strong>解释：</strong>爱丽丝选择 1，鲍勃也选择 1，然后爱丽丝无法进行操作。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 &lt;= N &lt;= 1000</code></li>
</ol>


---
### 思路
```
```



### 答题
``` C++
bool divisorGame(int N) 
{
    vector<bool> dp(N, true);
    dp[0] = false;
    for (int n = 2; n <= N; n++)
    {
        bool flag = false;
        for (int x = 1; x < n; x++)
        {
            if (n % x != 0) continue;
            if (!dp[n - x - 1])
            {
                flag = true;
                break;
            }
        }
        dp[n - 1] = flag;
    }
    return dp[N - 1];
}
```




