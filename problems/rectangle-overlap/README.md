# `（简单）` [836.rectangle-overlap 矩形重叠](https://leetcode-cn.com/problems/rectangle-overlap/)

### 题目描述
<p>矩形以列表 <code>[x1, y1, x2, y2]</code> 的形式表示，其中 <code>(x1, y1)</code> 为左下角的坐标，<code>(x2, y2)</code> 是右上角的坐标。</p>

<p>如果相交的面积为正，则称两矩形重叠。需要明确的是，只在角或边接触的两个矩形不构成重叠。</p>

<p>给出两个矩形，判断它们是否重叠并返回结果。</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>rec1 = [0,0,2,2], rec2 = [1,1,3,3]
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>rec1 = [0,0,1,1], rec2 = [1,0,2,1]
<strong>输出：</strong>false
</pre>

<p><strong>说明：</strong></p>

<ol>
	<li>两个矩形 <code>rec1</code> 和 <code>rec2</code> 都以含有四个整数的列表的形式给出。</li>
	<li>矩形中的所有坐标都处于 <code>-10^9</code> 和 <code>10^9</code> 之间。</li>
</ol>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) 
    {
        bool x_overlap = !(rec1[2] <= rec2[0] || rec2[2] <= rec1[0]);
        bool y_overlap = !(rec1[3] <= rec2[1] || rec2[3] <= rec1[1]);
        return x_overlap && y_overlap;
    }
};
```




