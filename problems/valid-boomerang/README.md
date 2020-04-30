# `（简单）` [1037.valid-boomerang 有效的回旋镖](https://leetcode-cn.com/problems/valid-boomerang/)

### 题目描述
<p>回旋镖定义为一组三个点，这些点各不相同且<strong>不</strong>在一条直线上。</p>

<p>给出平面上三个点组成的列表，判断这些点是否可以构成回旋镖。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>[[1,1],[2,3],[3,2]]
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>[[1,1],[2,2],[3,3]]
<strong>输出：</strong>false</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>points.length == 3</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>0 <= points[i][j] <= 100</code></li>
</ol>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        //斜率公式变形： (x3-x2)(y2-y1) = (x2-x1)(y3-y2)
        return (points[2][0] - points[1][0]) * (points[1][1] - points[0][1]) != (points[1][0] - points[0][0]) * (points[2][1] - points[1][1]);
    }
};
```




