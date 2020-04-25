# `（困难）` [LCP_15.you-le-yuan-de-mi-gong 游乐园的迷宫](https://leetcode-cn.com/problems/you-le-yuan-de-mi-gong/)
[contest](https://leetcode-cn.com/contest/season/2020-spring/problems/you-le-yuan-de-mi-gong/)

### 题目描述
<p>小王来到了游乐园，她玩的第一个项目是模拟推销员。有一个二维平面地图，其中散布着 <code>N</code> 个推销点，编号 <code>0</code> 到 <code>N-1</code>，不存在三点共线的情况。每两点之间有一条直线相连。游戏没有规定起点和终点，但限定了每次转角的方向。首先，小王需要先选择两个点分别作为起点和终点，然后从起点开始访问剩余 <code>N-2</code> 个点恰好一次并回到终点。访问的顺序需要满足一串给定的长度为 <code>N-2</code> 由 <code>L</code> 和 <code>R</code> 组成的字符串 <code>direction</code>，表示从起点出发之后在每个顶点上转角的方向。根据这个提示，小王希望你能够帮她找到一个可行的遍历顺序，输出顺序下标（若有多个方案，输出任意一种）。可以证明这样的遍历顺序一定是存在的。</p>

<p><img style="height:1000px" src="https://pic.leetcode-cn.com/595b60797d4a461287864a8cd05bba1d3b8760104ff83f43b902fd68477be9c3-Screenshot%202020-03-20%20at%2017.04.58.png" alt="Screenshot 2020-03-20 at 17.04.58.png"></p>

<p>（上图：A->B->C 右转； 下图：D->E->F 左转）</p>

<p><strong>示例 1：</strong></p>

<blockquote>
<p>输入：<code>points = [[1,1],[1,4],[3,2],[2,1]], direction = "LL"</code></p>

<p>输入：<code>[0,2,1,3]</code></p>

<p>解释：[0,2,1,3] 是符合"LL"的方案之一。在 [0,2,1,3] 方案中，0->2->1 是左转方向， 2->1->3 也是左转方向 <img style="height:500px" src="https://pic.leetcode-cn.com/c01c1efc423b916267c2a3a170266c925c368d62afa047c267cc1020970e55d9-%E5%9B%BE%E7%89%87.gif" alt="图片.gif"></p>
</blockquote>

<p><strong>示例 2：</strong></p>

<blockquote>
<p>输入：<code>points = [[1,3],[2,4],[3,3],[2,1]], direction = "LR"</code></p>

<p>输入：<code>[0,3,1,2]</code></p>

<p>解释：[0,3,1,2] 是符合"LR"的方案之一。在 [0,3,1,2] 方案中，0->3->1 是左转方向， 3->1->2 是右转方向</p>
</blockquote>

<p><strong>限制：</strong></p>

<ul>
	<li><code>3 <= points.length <= 1000 且 points[i].length == 2</code></li>
	<li><code>1 <= points[i][0],points[i][1] <= 10000</code></li>
	<li><code>direction.length == points.length - 2</code></li>
	<li><code>direction 只包含 "L","R"</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<int> visitOrder(vector<vector<int>>& points, string direction) {

    }
};
```




