# `（中等）` [6042.count-lattice-points-inside-a-circle 统计圆内格点数目](https://leetcode-cn.com/problems/count-lattice-points-inside-a-circle/)

[contest](https://leetcode-cn.com/contest/weekly-contest-290/problems/count-lattice-points-inside-a-circle/)

### 题目描述
<p>给你一个二维整数数组 <code>circles</code> ，其中 <code>circles[i] = [x<sub>i</sub>, y<sub>i</sub>, r<sub>i</sub>]</code> 表示网格上圆心为 <code>(x<sub>i</sub>, y<sub>i</sub>)</code> 且半径为 <code>r<sub>i</sub></code> 的第 <code>i</code> 个圆，返回出现在<strong> 至少一个 </strong>圆内的 <strong>格点数目</strong> 。</p>

<p><strong>注意：</strong></p>

<ul>
	<li><strong>格点</strong> 是指整数坐标对应的点。</li>
	<li><strong>圆周上的点</strong> 也被视为出现在圆内的点。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img style="width: 300px; height: 300px;" src="https://assets.leetcode.com/uploads/2022/03/02/exa-11.png" alt=""></p>

<pre><strong>输入：</strong>circles = [[2,2,1]]
<strong>输出：</strong>5
<strong>解释：</strong>
给定的圆如上图所示。
出现在圆内的格点为 (1, 2)、(2, 1)、(2, 2)、(2, 3) 和 (3, 2)，在图中用绿色标识。
像 (1, 1) 和 (1, 3) 这样用红色标识的点，并未出现在圆内。
因此，出现在至少一个圆内的格点数目是 5 。</pre>

<p><strong>示例 2：</strong></p>

<p><img style="width: 300px; height: 300px;" src="https://assets.leetcode.com/uploads/2022/03/02/exa-22.png" alt=""></p>

<pre><strong>输入：</strong>circles = [[2,2,2],[3,4,1]]
<strong>输出：</strong>16
<strong>解释：</strong>
给定的圆如上图所示。
共有 16 个格点出现在至少一个圆内。
其中部分点的坐标是 (0, 2)、(2, 0)、(2, 4)、(3, 2) 和 (4, 4) 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= circles.length &lt;= 200</code></li>
	<li><code>circles[i].length == 3</code></li>
	<li><code>1 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 100</code></li>
	<li><code>1 &lt;= r<sub>i</sub> &lt;= min(x<sub>i</sub>, y<sub>i</sub>)</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/count-lattice-points-inside-a-circle/solution/by-ikaruga-05vm/)

### 答题
``` C++
class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int ans = 0;
        for (int i = 0; i < 201; i++) {
            for (int j = 0; j < 201; j++) {
                ans += check(circles, i, j);
            }
        }
        return ans;
    }

    bool check(vector<vector<int>>& circles, int x, int y) {
        for (auto& circle : circles) {
            int a = x - circle[0];
            int b = y - circle[1];
            int r = circle[2];
            if (a * a + b * b <= r * r) return true;
        }
        return false;
    }
};
```




