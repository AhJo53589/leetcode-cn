# `（中等）` [6043.count-number-of-rectangles-containing-each-point 统计包含每个点的矩形数目](https://leetcode-cn.com/problems/count-number-of-rectangles-containing-each-point/)

[contest](https://leetcode-cn.com/contest/weekly-contest-290/problems/count-number-of-rectangles-containing-each-point/)

### 题目描述
<p>给你一个二维整数数组&nbsp;<code>rectangles</code>&nbsp;，其中&nbsp;<code>rectangles[i] = [l<sub>i</sub>, h<sub>i</sub>]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;个矩形长为&nbsp;<code>l<sub>i</sub></code>&nbsp;高为&nbsp;<code>h<sub>i</sub></code>&nbsp;。给你一个二维整数数组&nbsp;<code>points</code>&nbsp;，其中&nbsp;<code>points[j] = [x<sub>j</sub>, y<sub>j</sub>]</code>&nbsp;是坐标为&nbsp;<code>(x<sub>j</sub>, y<sub>j</sub>)</code>&nbsp;的一个点。</p>

<p>第&nbsp;<code>i</code>&nbsp;个矩形的 <strong>左下角</strong>&nbsp;在&nbsp;<code>(0, 0)</code>&nbsp;处，<strong>右上角</strong>&nbsp;在&nbsp;<code>(l<sub>i</sub>, h<sub>i</sub>)</code>&nbsp;。</p>

<p>请你返回一个整数数组<em>&nbsp;</em><code>count</code>&nbsp;，长度为&nbsp;<code>points.length</code>，其中<em>&nbsp;</em><code>count[j]</code>是 <strong>包含</strong> 第<em>&nbsp;</em><code>j</code>&nbsp;个点的矩形数目。</p>

<p>如果&nbsp;<code>0 &lt;= x<sub>j</sub> &lt;= l<sub>i</sub></code> 且&nbsp;<code>0 &lt;= y<sub>j</sub> &lt;= h<sub>i</sub></code>&nbsp;，那么我们说第&nbsp;<code>i</code>&nbsp;个矩形包含第&nbsp;<code>j</code>&nbsp;个点。如果一个点刚好在矩形的 <strong>边上</strong>&nbsp;，这个点也被视为被矩形包含。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img style="width: 300px; height: 509px;" src="https://assets.leetcode.com/uploads/2022/03/02/example1.png" alt=""></p>

<pre><b>输入：</b>rectangles = [[1,2],[2,3],[2,5]], points = [[2,1],[1,4]]
<b>输出：</b>[2,1]
<b>解释：</b>
第一个矩形不包含任何点。
第二个矩形只包含一个点 (2, 1) 。
第三个矩形包含点 (2, 1) 和 (1, 4) 。
包含点 (2, 1) 的矩形数目为 2 。
包含点 (1, 4) 的矩形数目为 1 。
所以，我们返回 [2, 1] 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img style="width: 300px; height: 312px;" src="https://assets.leetcode.com/uploads/2022/03/02/example2.png" alt=""></p>

<pre><b>输入：</b>rectangles = [[1,1],[2,2],[3,3]], points = [[1,3],[1,1]]
<b>输出：</b>[1,3]
<strong>解释：
</strong>第一个矩形只包含点 (1, 1) 。
第二个矩形只包含点 (1, 1) 。
第三个矩形包含点 (1, 3) 和 (1, 1) 。
包含点 (1, 3) 的矩形数目为 1 。
包含点 (1, 1) 的矩形数目为 3 。
所以，我们返回 [1, 3] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= rectangles.length, points.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>rectangles[i].length == points[j].length == 2</code></li>
	<li><code>1 &lt;= l<sub>i</sub>, x<sub>j</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= h<sub>i</sub>, y<sub>j</sub> &lt;= 100</code></li>
	<li>所有&nbsp;<code>rectangles</code>&nbsp;<strong>互不相同</strong>&nbsp;。</li>
	<li>所有&nbsp;<code>points</code> <strong>互不相同</strong>&nbsp;。</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/count-number-of-rectangles-containing-each-point/solution/by-ikaruga-v7dw/)

### 答题
``` C++
class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int>> rect(101, vector<int>());
        for (int i = 0; i < rectangles.size(); i++) {
            rect[rectangles[i][1]].push_back(rectangles[i][0]);
        }
        for (auto& rt : rect) {
            sort(rt.begin(), rt.end());
        }

        vector<int> ans(points.size(), 0);
        for (int i = 0; i < points.size(); i++) {
            int cnt = 0;
            int l = points[i][0];
            for (int h = points[i][1]; h < rect.size(); h++) {
                auto& rt = rect[h];
                auto t = lower_bound(rt.begin(), rt.end(), l) - rt.begin();
                cnt += (int)rt.size() - t;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};
```




