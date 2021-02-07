# `（中等）` [5673.maximum-score-from-removing-stones 移除石子的最大得分](https://leetcode-cn.com/problems/maximum-score-from-removing-stones/)

[contest](https://leetcode-cn.com/contest/weekly-contest-227/problems/maximum-score-from-removing-stones/)

### 题目描述
<p>你正在玩一个单人游戏，面前放置着大小分别为 <code>a</code>​​​​​​、<code>b</code> 和 <code>c</code>​​​​​​ 的 <strong>三堆</strong> 石子。</p>

<p>每回合你都要从两个 <strong>不同的非空堆</strong> 中取出一颗石子，并在得分上加 <code>1</code> 分。当存在 <strong>两个或更多</strong> 的空堆时，游戏停止。</p>

<p>给你三个整数 <code>a</code> 、<code>b</code> 和 <code>c</code> ，返回可以得到的 <strong>最大分数</strong> 。</p>
&nbsp;

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>a = 2, b = 4, c = 6
<strong>输出：</strong>6
<strong>解释：</strong>石子起始状态是 (2, 4, 6) ，最优的一组操作是：
- 从第一和第三堆取，石子状态现在是 (1, 4, 5)
- 从第一和第三堆取，石子状态现在是 (0, 4, 4)
- 从第二和第三堆取，石子状态现在是 (0, 3, 3)
- 从第二和第三堆取，石子状态现在是 (0, 2, 2)
- 从第二和第三堆取，石子状态现在是 (0, 1, 1)
- 从第二和第三堆取，石子状态现在是 (0, 0, 0)
总分：6 分 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>a = 4, b = 4, c = 6
<strong>输出：</strong>7
<strong>解释：</strong>石子起始状态是 (4, 4, 6) ，最优的一组操作是：
- 从第一和第二堆取，石子状态现在是 (3, 3, 6)
- 从第一和第三堆取，石子状态现在是 (2, 3, 5)
- 从第一和第三堆取，石子状态现在是 (1, 3, 4)
- 从第一和第三堆取，石子状态现在是 (0, 3, 3)
- 从第二和第三堆取，石子状态现在是 (0, 2, 2)
- 从第二和第三堆取，石子状态现在是 (0, 1, 1)
- 从第二和第三堆取，石子状态现在是 (0, 0, 0)
总分：7 分 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>a = 1, b = 8, c = 8
<strong>输出：</strong>8
<strong>解释：</strong>最优的一组操作是连续从第二和第三堆取 8 回合，直到将它们取空。
注意，由于第二和第三堆已经空了，游戏结束，不能继续从第一堆中取石子。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= a, b, c &lt;= 10<sup>5</sup></code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/maximum-score-from-removing-stones/solution/maximum-score-by-ikaruga-0trm/)

### 答题
``` C++
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int ans = 0;
        
        vector<int> stone = { a, b, c };
        sort(stone.begin(), stone.end());
        
        if (stone[1] != stone[2]) {
            int dif = stone[2] - stone[1];
            dif = min(stone[0], dif);
            ans += dif;
            stone[0] -= dif;
            stone[2] -= dif;
        }
        
        if (stone[0] != 0) {
            int dif = stone[0] / 2;
            dif = min(stone[1], dif);
            ans += dif * 2;
            // stone[0] -= dif * 2;
            // stone[1] -= dif;
            stone[2] -= dif;
            return ans + stone[2];
        } 
        
        return ans + min(stone[1], stone[2]);
    }
};
```




