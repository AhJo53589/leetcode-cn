# `（困难）` [1453.maximum-number-of-darts-inside-of-a-circular-dartboard 圆形靶内的最大飞镖数量](https://leetcode-cn.com/problems/maximum-number-of-darts-inside-of-a-circular-dartboard/)

[contest](https://leetcode-cn.com/contest/weekly-contest-189/problems/maximum-number-of-darts-inside-of-a-circular-dartboard/)

### 题目描述
<p>墙壁上挂着一个圆形的飞镖靶。现在请你蒙着眼睛向靶上投掷飞镖。</p>

<p>投掷到墙上的飞镖用二维平面上的点坐标数组表示。飞镖靶的半径为 <code>r</code> 。</p>

<p>请返回能够落在 <strong>任意</strong> 半径为 <code>r</code> 的圆形靶内或靶上的最大飞镖数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img style="height: 159px; width: 186px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/05/16/sample_1_1806.png" alt=""></p>

<pre><strong>输入：</strong>points = [[-2,0],[2,0],[0,2],[0,-2]], r = 2
<strong>输出：</strong>4
<strong>解释：</strong>如果圆形的飞镖靶的圆心为 (0,0) ，半径为 2 ，所有的飞镖都落在靶上，此时落在靶上的飞镖数最大，值为 4 。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img style="height: 183px; width: 224px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/05/16/sample_2_1806.png" alt=""></strong></p>

<pre><strong>输入：</strong>points = [[-3,0],[3,0],[2,6],[5,4],[0,9],[7,8]], r = 5
<strong>输出：</strong>5
<strong>解释：</strong>如果圆形的飞镖靶的圆心为 (0,4) ，半径为 5 ，则除了 (7,8) 之外的飞镖都落在靶上，此时落在靶上的飞镖数最大，值为 5 。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>points = [[-2,0],[2,0],[0,2],[0,-2]], r = 1
<strong>输出：</strong>1
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>points = [[1,2],[3,5],[1,-1],[2,3],[4,1],[1,3]], r = 2
<strong>输出：</strong>4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= points.length <= 100</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>-10^4 <= points[i][0], points[i][1] <= 10^4</code></li>
	<li><code>1 <= r <= 5000</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int numPoints(vector<vector<int>>& points, int r) {

    }
};
```


### 其它
``` C++
struct Point {
	double x, y;
	Point() {}
	Point(double tx, double ty) { x = tx; y = ty; }
};
const double eps = 1e-10;
class Solution {
public:
    double dist(Point p1,Point p2) {
	    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    }

    Point GetCircleCenter(Point p1, Point p2, double r) {
	    Point mid = Point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
	    double angle = atan2(p1.x - p2.x, p2.y - p1.y);
	    double d = sqrt(r*r - pow(dist(p1, mid), 2));
	    return Point(mid.x + d*cos(angle), mid.y + d*sin(angle));
    }
    
    int numPoints(vector<vector<int>>& points, int r) {
        int ans = 1;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                if(dist(Point(1.0 * points[i][0], 1.0 * points[i][1]), 
                        Point(1.0 * points[j][0], 1.0 * points[j][1])) > 2.0*r)
                    continue;
                Point center = GetCircleCenter(
                               Point(1.0 * points[i][0], 1.0 * points[i][1]), 
                               Point(1.0 * points[j][0], 1.0 * points[j][1]), 
                               1.0 * r
                               );
                int cnt = 0;
				for(int k = 0; k < points.size(); ++k)
                    if(dist(center, Point(1.0 * points[k][0], 1.0 * points[k][1])) 
                       < 1.0*r + eps) 
                        cnt++;
				ans = max(ans,cnt);
            } 
        }
        return ans;
    }
};


```


