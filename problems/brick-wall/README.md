# `（中等）` [554.brick-wall 砖墙](https://leetcode-cn.com/problems/brick-wall/)

### 题目描述
<div class="notranslate"><p>你的面前有一堵矩形的、由 <code>n</code> 行砖块组成的砖墙。这些砖块高度相同（也就是一个单位高）但是宽度不同。每一行砖块的宽度之和应该相等。</p>

<p>你现在要画一条 <strong>自顶向下 </strong>的、穿过 <strong>最少 </strong>砖块的垂线。如果你画的线只是从砖块的边缘经过，就不算穿过这块砖。<strong>你不能沿着墙的两个垂直边缘之一画线，这样显然是没有穿过一块砖的。</strong></p>

<p>给你一个二维数组 <code>wall</code> ，该数组包含这堵墙的相关信息。其中，<code>wall[i]</code> 是一个代表从左至右每块砖的宽度的数组。你需要找出怎样画才能使这条线 <strong>穿过的砖块数量最少</strong> ，并且返回 <strong>穿过的砖块数量</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img style="width: 493px; height: 577px;" src="https://assets.leetcode.com/uploads/2021/04/24/cutwall-grid.jpg" alt="">
<pre><strong>输入：</strong>wall = [[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]
<strong>输出：</strong>2
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>wall = [[1],[1],[1]]
<strong>输出：</strong>3
</pre>
&nbsp;

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == wall.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= wall[i].length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= sum(wall[i].length) &lt;= 2 * 10<sup>4</sup></code></li>
	<li>对于每一行 <code>i</code> ，<code>sum(wall[i])</code> 应当是相同的</li>
	<li><code>1 &lt;= wall[i][j] &lt;= 2<sup>31</sup> - 1</code></li>
</ul>
</div>

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/brick-wall/solution/brick-wall-by-ikaruga-hg4w/)

### 答题
``` C++
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int ans = 0;
        unordered_map<int, int> dic;
        for (auto& w : wall) {
            for (int i = 1; i < w.size(); i++) {
                dic[w[i - 1]]++;
                ans = max(ans, dic[w[i - 1]]);
                w[i] += w[i - 1];
            }
        }
        return (int)wall.size() - ans;
    }
};
```




