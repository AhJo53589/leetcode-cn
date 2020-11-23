# `（中等）` [452.minimum-number-of-arrows-to-burst-balloons 用最少数量的箭引爆气球](https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/)

### 题目描述
<p>在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。由于它是水平的，所以纵坐标并不重要，因此只要知道开始和结束的横坐标就足够了。开始坐标总是小于结束坐标。</p>

<p>一支弓箭可以沿着 x 轴从不同点完全垂直地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 <code>x</code><sub><code>start</code>，</sub><code>x</code><sub><code>end</code>，</sub> 且满足 &nbsp;<code>x<sub>start</sub>&nbsp;≤ x ≤ x</code><sub><code>end</code>，</sub>则该气球会被引爆<sub>。</sub>可以射出的弓箭的数量没有限制。 弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。</p>

<p>给你一个数组 <code>points</code> ，其中 <code>points [i] = [x<sub>start</sub>,x<sub>end</sub>]</code> ，返回引爆所有气球所必须射出的最小弓箭数。</p>
&nbsp;

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>points = [[10,16],[2,8],[1,6],[7,12]]
<strong>输出：</strong>2
<strong>解释：</strong>对于该样例，x = 6 可以射爆 [2,8],[1,6] 两个气球，以及 x = 11 射爆另外两个气球</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>points = [[1,2],[3,4],[5,6],[7,8]]
<strong>输出：</strong>4
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>points = [[1,2],[2,3],[3,4],[4,5]]
<strong>输出：</strong>2
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>points = [[1,2]]
<strong>输出：</strong>1
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>points = [[2,3],[2,3]]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= points.length &lt;= 10<sup>4</sup></code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>-2<sup>31</sup> &lt;= x<sub>start</sub> &lt;&nbsp;x<sub>end</sub> &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int ans = 0;
        int shoot = INT_MIN;
        for (auto& p : points) {
            if (ans == 0 || p[0] > shoot) {
                ans++;
                shoot = p[1];
            }
        }
        return ans;
    }
};
```




