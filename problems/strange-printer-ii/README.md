# `（困难）` [5506.strange-printer-ii 奇怪的打印机 II](https://leetcode-cn.com/problems/strange-printer-ii/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-35/problems/strange-printer-ii/)

### 题目描述
<p>给你一个奇怪的打印机，它有如下两个特殊的打印规则：</p>

<ul>
	<li>每一次操作时，打印机会用同一种颜色打印一个矩形的形状，每次打印会覆盖矩形对应格子里原本的颜色。</li>
	<li>一旦矩形根据上面的规则使用了一种颜色，那么 <strong>相同的颜色不能再被使用&nbsp;</strong>。</li>
</ul>

<p>给你一个初始没有颜色的&nbsp;<code>m x n</code>&nbsp;的矩形&nbsp;<code>targetGrid</code>&nbsp;，其中&nbsp;<code>targetGrid[row][col]</code>&nbsp;是位置&nbsp;<code>(row, col)</code>&nbsp;的颜色。</p>

<p>如果你能按照上述规则打印出矩形<em>&nbsp;</em><code>targetGrid</code>&nbsp;，请你返回&nbsp;<code>true</code>&nbsp;，否则返回&nbsp;<code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img style="height: 138px; width: 483px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/09/19/sample_1_1929.png" alt=""></p>

<pre><strong>输入：</strong>targetGrid = [[1,1,1,1],[1,2,2,1],[1,2,2,1],[1,1,1,1]]
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<p><img style="height: 290px; width: 483px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/09/19/sample_2_1929.png" alt=""></p>

<pre><strong>输入：</strong>targetGrid = [[1,1,1,1],[1,1,3,3],[1,1,3,4],[5,5,1,4]]
<strong>输出：</strong>true
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>targetGrid = [[1,2,1],[2,1,2],[1,2,1]]
<strong>输出：</strong>false
<strong>解释：</strong>没有办法得到 targetGrid ，因为每一轮操作使用的颜色互不相同。</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>targetGrid = [[1,1,1],[3,1,3]]
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == targetGrid.length</code></li>
	<li><code>n == targetGrid[i].length</code></li>
	<li><code>1 <= m, n <= 60</code></li>
	<li><code>1 <= targetGrid[row][col] <= 60</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {

    }
};
```




