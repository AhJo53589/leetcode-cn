# `（中等）` [5361.circle-and-rectangle-overlapping 圆和矩形是否有重叠](https://leetcode-cn.com/problems/circle-and-rectangle-overlapping/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-23/problems/circle-and-rectangle-overlapping/)

### 题目描述
<p>给你一个以 (<code>radius</code>, <code>x_center</code>, <code>y_center</code>) 表示的圆和一个与坐标轴平行的矩形 (<code>x1</code>, <code>y1</code>, <code>x2</code>, <code>y2</code>)，其中&nbsp;(<code>x1</code>, <code>y1</code>) 是矩形左下角的坐标，(<code>x2</code>, <code>y2</code>) 是右上角的坐标。</p>

<p>如果圆和矩形有重叠的部分，请你返回 True ，否则返回 False&nbsp;。</p>

<p>换句话说，请你检测是否 <strong>存在</strong> 点&nbsp;(xi, yi) ，它既在圆上也在矩形上（两者都包括点落在边界上的情况）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img style="height: 167px; width: 258px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/04/04/sample_4_1728.png" alt=""></p>

<pre><strong>输入：</strong>radius = 1, x_center = 0, y_center = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
<strong>输出：</strong>true
<strong>解释：</strong>圆和矩形有公共点 (1,0) 
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img style="height: 135px; width: 150px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/04/04/sample_2_1728.png" alt=""></strong></p>

<pre><strong>输入：</strong>radius = 1, x_center = 0, y_center = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1
<strong>输出：</strong>true
</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img style="height: 165px; width: 175px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/04/04/sample_6_1728.png" alt=""></strong></p>

<pre><strong>输入：</strong>radius = 1, x_center = 1, y_center = 1, x1 = -3, y1 = -3, x2 = 3, y2 = 3
<strong>输出：</strong>true
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>radius = 1, x_center = 1, y_center = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= radius <= 2000</code></li>
	<li><code>-10^4 <= x_center, y_center, x1, y1, x2, y2 <= 10^4</code></li>
	<li><code>x1 < x2</code></li>
	<li><code>y1 < y2</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/circle-and-rectangle-overlapping/solution/circle-and-rectangle-overlapping-by-ikaruga/)

### 答题
``` C++
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) 
    {
        double x0 = (x1 + x2) / 2.0;
        double y0 = (y1 + y2) / 2.0;

        vector<double> p = { abs(x_center - x0) , abs(y_center - y0) };
        vector<double> q = { x2 - x0, y2 - y0 };
        
        vector<double> u = { max(p[0] - q[0], 0.0), max(p[1] - q[1], 0.0) };

        return sqrt(u[0] * u[0] + u[1] * u[1]) <= radius;   
    }
```




