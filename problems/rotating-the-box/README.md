# `（中等）` [1861.rotating-the-box 旋转盒子](https://leetcode-cn.com/problems/rotating-the-box/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-52/problems/rotating-the-box/)

### 题目描述
<p>给你一个&nbsp;<code>m x n</code>&nbsp;的字符矩阵&nbsp;<code>box</code>&nbsp;，它表示一个箱子的侧视图。箱子的每一个格子可能为：</p>

<ul>
	<li><code>'#'</code>&nbsp;表示石头</li>
	<li><code>'*'</code>&nbsp;表示固定的障碍物</li>
	<li><code>'.'</code>&nbsp;表示空位置</li>
</ul>

<p>这个箱子被 <strong>顺时针旋转 90 度</strong>&nbsp;，由于重力原因，部分石头的位置会发生改变。每个石头会垂直掉落，直到它遇到障碍物，另一个石头或者箱子的底部。重力 <strong>不会</strong>&nbsp;影响障碍物的位置，同时箱子旋转不会产生<strong>惯性</strong>&nbsp;，也就是说石头的水平位置不会发生改变。</p>

<p>题目保证初始时&nbsp;<code>box</code>&nbsp;中的石头要么在一个障碍物上，要么在另一个石头上，要么在箱子的底部。</p>

<p>请你返回一个<em>&nbsp;</em><code>n x m</code>的矩阵，表示按照上述旋转后，箱子内的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img style="width: 300px; height: 150px;" src="https://assets.leetcode.com/uploads/2021/04/08/rotatingtheboxleetcodewithstones.png" alt=""></p>

<pre><b>输入：</b>box = [["#",".","#"]]
<b>输出：</b>[["."],
&nbsp;     ["#"],
&nbsp;     ["#"]]
</pre>

<p><strong>示例 2：</strong></p>

<p><img style="width: 375px; height: 195px;" src="https://assets.leetcode.com/uploads/2021/04/08/rotatingtheboxleetcode2withstones.png" alt=""></p>

<pre><b>输入：</b>box = [["#",".","*","."],
&nbsp;           ["#","#","*","."]]
<b>输出：</b>[["#","."],
&nbsp;     ["#","#"],
&nbsp;     ["*","*"],
&nbsp;     [".","."]]
</pre>

<p><strong>示例 3：</strong></p>

<p><img style="width: 400px; height: 218px;" src="https://assets.leetcode.com/uploads/2021/04/08/rotatingtheboxleetcode3withstone.png" alt=""></p>

<pre><b>输入：</b>box = [["#","#","*",".","*","."],
&nbsp;           ["#","#","#","*",".","."],
&nbsp;           ["#","#","#",".","#","."]]
<b>输出：</b>[[".","#","#"],
&nbsp;     [".","#","#"],
&nbsp;     ["#","#","*"],
&nbsp;     ["#","*","."],
&nbsp;     ["#",".","*"],
&nbsp;     ["#",".","."]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == box.length</code></li>
	<li><code>n == box[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 500</code></li>
	<li><code>box[i][j]</code>&nbsp;只可能是&nbsp;<code>'#'</code>&nbsp;，<code>'*'</code>&nbsp;或者&nbsp;<code>'.'</code>&nbsp;。</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        vector<vector<char>> ans = vector<vector<char>>(box[0].size(), vector<char>(box.size()));
        for (int i = 0; i < box[0].size(); i++) {
            for (int j = 0; j < box.size(); j++) {
                int x = (int)box.size() - j - 1;
                ans[i][x] = box[j][i];
            }
        }

        for (int j = 0; j < ans[0].size(); j++) {
            vector<int> emptyPos;
            int emptyIdx = 0;
            for (int i = (int)ans.size() - 1; i >= 0; i--) {
                if (ans[i][j] == '.') {
                    emptyPos.push_back(i);
                }
                else if (ans[i][j] == '#' && emptyIdx < emptyPos.size()) {
                    ans[emptyPos[emptyIdx]][j] = '#';
                    emptyIdx++;
                    ans[i][j] = '.';
                    emptyPos.push_back(i);
                }
                else {
                    emptyPos.clear();
                    emptyIdx = 0;
                }
            }
        }

        return ans;
    }
};
```




