# `（困难）` [LCP 21.Za25hA 追逐游戏](https://leetcode-cn.com/problems/Za25hA/)

### 题目描述
<p>秋游中的小力和小扣设计了一个追逐游戏。他们选了秋日市集景区中的 N 个景点，景点编号为 1~N。此外，他们还选择了 N 条小路，满足任意两个景点之间都可以通过小路互相到达，且不存在两条连接景点相同的小路。整个游戏场景可视作一个无向连通图，记作二维数组 <code>edges</code>，数组中以 <code>[a,b]</code> 形式表示景点 a 与景点 b 之间有一条小路连通。</p>
<p>小力和小扣只能沿景点间的小路移动。小力的目标是在最快时间内追到小扣，小扣的目标是尽可能延后被小力追到的时间。游戏开始前，两人分别站在两个不同的景点 <code>startA</code> 和 <code>startB</code>。每一回合，小力先行动，小扣观察到小力的行动后再行动。小力和小扣在每回合可选择以下行动之一：</p>
<ul>
<li>移动至相邻景点</li>
<li>留在原地</li>
</ul>
<p>如果小力追到小扣（即两人于某一时刻出现在同一位置），则游戏结束。若小力可以追到小扣，请返回最少需要多少回合；若小力无法追到小扣，请返回 -1。</p>
<p>注意：小力和小扣一定会采取最优移动策略。</p>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>edges = [[1,2],[2,3],[3,4],[4,1],[2,5],[5,6]], startA = 3, startB = 5</code></p>
<p>输出：<code>3</code></p>
<p>解释：<br>
<img src="https://pic.leetcode-cn.com/1597991318-goeHHr-image.png" alt="image.png" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; " height="250px"></p>
<p>第一回合，小力移动至 2 号点，小扣观察到小力的行动后移动至 6 号点；<br>
第二回合，小力移动至 5 号点，小扣无法移动，留在原地；<br>
第三回合，小力移动至 6 号点，小力追到小扣。返回 3。</p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>edges = [[1,2],[2,3],[3,4],[4,1]], startA = 1, startB = 3</code></p>
<p>输出：<code>-1</code></p>
<p>解释：<br>
<img src="https://pic.leetcode-cn.com/1597991157-QfeakF-image.png" alt="image.png" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; " height="250px"></p>
<p>小力如果不动，则小扣也不动；否则小扣移动到小力的对角线位置。这样小力无法追到小扣。</p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>edges</code> 的长度等于图中节点个数</li>
<li><code>3 &lt;= edges.length &lt;= 10^5</code></li>
<li><code>1 &lt;= edges[i][0], edges[i][1] &lt;= edges.length 且 edges[i][0] != edges[i][1]</code></li>
<li><code>1 &lt;= startA, startB &lt;= edges.length 且 startA != startB</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int chaseGame(vector<vector<int>>& edges, int startA, int startB) {

    }
};
```




