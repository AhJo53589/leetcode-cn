# `（困难）` [LCP_38.7rLGCR 守卫城堡](https://leetcode-cn.com/problems/7rLGCR/)

[contest](https://leetcode-cn.com/contest/season/2021-spring/problems/7rLGCR/)

### 题目描述
<p>城堡守卫游戏的胜利条件为使恶魔无法从出生点到达城堡。游戏地图可视作 <code>2*N</code> 的方格图，记作字符串数组 <code>grid</code>，其中：</p>
<ul>
<li><code>"."</code> 表示恶魔可随意通行的平地；</li>
<li><code>"#"</code> 表示恶魔不可通过的障碍物，玩家可通过在 <strong>平地</strong> 上设置障碍物，即将  <code>"."</code> 变为 <code>"#"</code> 以阻挡恶魔前进；</li>
<li><code>"S"</code> 表示恶魔出生点，将有大量的恶魔该点生成，恶魔可向上/向下/向左/向右移动，且无法移动至地图外；</li>
<li><code>"P"</code> 表示瞬移点，移动到 <code>"P"</code> 点的恶魔可被传送至任意一个 <code>"P"</code> 点，也可选择不传送；</li>
<li><code>"C"</code> 表示城堡。</li>
</ul>
<p>然而在游戏中用于建造障碍物的金钱是有限的，请返回玩家最少需要放置几个障碍物才能获得胜利。若无论怎样放置障碍物均无法获胜，请返回 <code>-1</code>。</p>
<p><strong>注意：</strong></p>
<ul>
<li>地图上可能有一个或多个出生点</li>
<li>地图上有且只有一个城堡</li>
</ul>
<p><strong>示例 1</strong></p>
<blockquote>
<p>输入：<code>grid = ["S.C.P#P.", ".....#.S"]</code></p>
<p>输出：<code>3</code></p>
<p>解释：至少需要放置三个障碍物<br>
<img src="https://pic.leetcode-cn.com/1614828255-uuNdNJ-image.png" alt="image.png" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; "></p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>grid = ["SP#P..P#PC#.S", "..#P..P####.#"]</code></p>
<p>输出：<code>-1</code></p>
<p>解释：无论怎样修筑障碍物，均无法阻挡最左侧出生的恶魔到达城堡位置<br>
<img src="https://pic.leetcode-cn.com/1614828208-oFlpVs-image.png" alt="image.png" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; "></p>
</blockquote>
<p><strong>示例 3：</strong></p>
<blockquote>
<p>输入：<code>grid = ["SP#.C.#PS", "P.#...#.P"]</code></p>
<p>输出：<code>0</code></p>
<p>解释：无需放置障碍物即可获得胜利<br>
<img src="https://pic.leetcode-cn.com/1614828242-oveClu-image.png" alt="image.png" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; "></p>
</blockquote>
<p><strong>示例 4：</strong></p>
<blockquote>
<p>输入：<code>grid = ["CP.#.P.", "...S..S"]</code></p>
<p>输出：<code>4</code></p>
<p>解释：至少需要放置 4 个障碍物，示意图为放置方法之一<br>
<img src="https://pic.leetcode-cn.com/1614828218-sIAYkb-image.png" alt="image.png" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; "></p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>grid.length == 2</code></li>
<li><code>2 &lt;= grid[0].length == grid[1].length &lt;= 10^4</code></li>
<li><code>grid[i][j]</code> 仅包含字符 <code>"."</code>、<code>"#"</code>、<code>"C"</code>、<code>"P"</code>、<code>"S"</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int guardCastle(vector<string>& grid) {

    }
};
```




