# `（困难）` [LCP_31.Db3wC1 变换的迷宫](https://leetcode-cn.com/problems/Db3wC1/)

[contest](https://leetcode-cn.com/contest/season/2021-spring/problems/Db3wC1/)

### 题目描述
<div class="css-1708ckn" style="padding: 0px; margin: 13px 0px;"><p>某解密游戏中，有一个 N*M 的迷宫，迷宫地形会随时间变化而改变，迷宫出口一直位于 <code>(n-1,m-1)</code> 位置。迷宫变化规律记录于 <code>maze</code> 中，<code>maze[i]</code> 表示 <code>i</code> 时刻迷宫的地形状态，<code>"."</code> 表示可通行空地，<code>"#"</code> 表示陷阱。</p>
<p>地形图初始状态记作 <code>maze[0]</code>，此时小力位于起点 <code>(0,0)</code>。此后每一时刻可选择往上、下、左、右其一方向走一步，或者停留在原地。</p>
<p>小力背包有以下两个魔法卷轴（卷轴使用一次后消失）：</p>
<ul>
<li>临时消除术：将指定位置在下一个时刻变为空地；</li>
<li>永久消除术：将指定位置永久变为空地。</li>
</ul>
<p>请判断在迷宫变化结束前（含最后时刻），小力能否在不经过任意陷阱的情况下到达迷宫出口呢？</p>
<p><strong>注意： 输入数据保证起点和终点在所有时刻均为空地。</strong></p>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>maze = [[".#.","#.."],["...",".#."],[".##",".#."],["..#",".#."]]</code></p>
<p>输出：<code>true</code></p>
<p>解释：<br>
<img src="https://pic.leetcode-cn.com/1615892239-SCIjyf-maze.gif" alt="maze.gif" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; "></p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>maze = [[".#.","..."],["...","..."]]</code></p>
<p>输出：<code>false</code></p>
<p>解释：由于时间不够，小力无法到达终点逃出迷宫。</p>
</blockquote>
<p><strong>示例 3：</strong></p>
<blockquote>
<p>输入：<code>maze = [["...","...","..."],[".##","###","##."],[".##","###","##."],[".##","###","##."],[".##","###","##."],[".##","###","##."],[".##","###","##."]]</code></p>
<p>输出：<code>false</code></p>
<p>解释：由于道路不通，小力无法到达终点逃出迷宫。</p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>1 &lt;= maze.length &lt;= 100</code></li>
<li><code>1 &lt;= maze[i].length, maze[i][j].length &lt;= 50</code></li>
<li><code>maze[i][j]</code> 仅包含 <code>"."</code>、<code>"#"</code></li>
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
    bool escapeMaze(vector<vector<string>>& maze) {

    }
};
```




