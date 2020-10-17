# `（中等）` [5528.coordinate-with-maximum-network-quality 网络信号最好的坐标](https://leetcode-cn.com/problems/coordinate-with-maximum-network-quality/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-37/problems/coordinate-with-maximum-network-quality/)

### 题目描述
<p>给你一个数组 <code>towers</code>&nbsp;和一个整数 <code>radius</code>&nbsp;，数组中包含一些网络信号塔，其中&nbsp;<code>towers[i] = [x<sub>i</sub>, y<sub>i</sub>, q<sub>i</sub>]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;个网络信号塔的坐标是&nbsp;<code>(x<sub>i</sub>, y<sub>i</sub>)</code>&nbsp;且信号强度参数为&nbsp;<code>q<sub>i</sub></code><sub>&nbsp;</sub>。所有坐标都是在&nbsp; X-Y 坐标系内的&nbsp;<strong>整数</strong>&nbsp;坐标。两个坐标之间的距离用 <strong>欧几里得距离</strong>&nbsp;计算。</p>

<p>整数&nbsp;<code>radius</code>&nbsp;表示一个塔 <strong>能到达&nbsp;</strong>的 <strong>最远距离</strong>&nbsp;。如果一个坐标跟塔的距离在 <code>radius</code>&nbsp;以内，那么该塔的信号可以到达该坐标。在这个范围以外信号会很微弱，所以 <code>radius</code>&nbsp;以外的距离该塔是 <strong>不能到达的</strong>&nbsp;。</p>

<p>如果第 <code>i</code>&nbsp;个塔能到达 <code>(x, y)</code>&nbsp;，那么该塔在此处的信号为&nbsp;<code>⌊q<sub>i</sub> / (1 + d)⌋</code>&nbsp;，其中&nbsp;<code>d</code>&nbsp;是塔跟此坐标的距离。一个坐标的 <b>网络信号</b>&nbsp;是所有 <strong>能到达&nbsp;</strong>该坐标的塔的信号强度之和。</p>

<p>请你返回 <strong>网络信号</strong>&nbsp;最大的整数坐标点。如果有多个坐标网络信号一样大，请你返回字典序最小的一个坐标。</p>

<p><strong>注意：</strong></p>

<ul>
	<li>坐标&nbsp;<code>(x1, y1)</code>&nbsp;字典序比另一个坐标&nbsp;<code>(x2, y2)</code>&nbsp;小：要么&nbsp;<code>x1 &lt; x2</code>&nbsp;，要么&nbsp;<code>x1 == x2</code> 且&nbsp;<code>y1 &lt; y2</code>&nbsp;。</li>
	<li><code>⌊val⌋</code>&nbsp;表示小于等于&nbsp;<code>val</code>&nbsp;的最大整数（向下取整函数）。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img style="width: 176px; height: 176px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/10/17/untitled-diagram.png" alt="">
<pre><b>输入：</b>towers = [[1,2,5],[2,1,7],[3,1,9]], radius = 2
<b>输出：</b>[2,1]
<strong>解释：</strong>
坐标 (2, 1) 信号强度之和为 13
- 塔 (2, 1) 强度参数为 7 ，在该点强度为 ⌊7 / (1 + sqrt(0)⌋ = ⌊7⌋ = 7
- 塔 (1, 2) 强度参数为 5 ，在该点强度为 ⌊5 / (1 + sqrt(2)⌋ = ⌊2.07⌋ = 2
- 塔 (3, 1) 强度参数为 9 ，在该点强度为 ⌊9 / (1 + sqrt(1)⌋ = ⌊4.5⌋ = 4
没有别的坐标有更大的信号强度。</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>towers = [[23,11,21]], radius = 9
<b>输出：</b>[23,11]
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>towers = [[1,2,13],[2,1,7],[0,1,9]], radius = 2
<b>输出：</b>[1,2]
</pre>

<p><strong>示例 4：</strong></p>

<pre><b>输入：</b>towers = [[2,1,9],[0,1,9]], radius = 2
<b>输出：</b>[0,1]
<strong>解释：</strong>坐标 (0, 1) 和坐标 (2, 1) 都是强度最大的位置，但是 (0, 1) 字典序更小。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= towers.length &lt;= 50</code></li>
	<li><code>towers[i].length == 3</code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i</sub>, q<sub>i</sub> &lt;= 50</code></li>
	<li><code>1 &lt;= radius &lt;= 50</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        vector<vector<int>> quality(51, vector<int>(51, 0));
        vector<int> ans(3, 0);

        for (int i = 0; i <= 50; i++) {
            for (int j = 0; j <= 50; j++) {
                for (auto t : towers) {
                    double dis = getDis(i, j, t[0], t[1]);
                    if (radius < dis) continue;
                    quality[i][j] += (int)((double)t[2] / (double)(1 + dis));
                }
                int temp = quality[i][j];
                if (ans[2] < temp) {
                    ans = { i, j, temp };
                }
            }
        }

        return { ans[0], ans[1] };
    }

    double getDis(int i, int j, int x, int y) {
        double ans = sqrt((i - x) * (i - x) + (j - y) * (j - y));
        return ans;
    }
};
```




