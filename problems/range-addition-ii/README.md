# `（简单）` [598.range-addition-ii 范围求和 II](https://leetcode-cn.com/problems/range-addition-ii/)

### 题目描述
<div class="notranslate"><p>给定一个初始元素全部为&nbsp;<strong>0</strong>，大小为 m*n 的矩阵&nbsp;<strong>M&nbsp;</strong>以及在&nbsp;<strong>M&nbsp;</strong>上的一系列更新操作。</p>

<p>操作用二维数组表示，其中的每个操作用一个含有两个<strong>正整数&nbsp;a</strong> 和 <strong>b</strong> 的数组表示，含义是将所有符合&nbsp;<strong>0 &lt;= i &lt; a</strong> 以及 <strong>0 &lt;= j &lt; b</strong> 的元素&nbsp;<strong>M[i][j]&nbsp;</strong>的值都<strong>增加 1</strong>。</p>

<p>在执行给定的一系列操作后，你需要返回矩阵中含有最大整数的元素个数。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 
m = 3, n = 3
operations = [[2,2],[3,3]]
<strong>输出:</strong> 4
<strong>解释:</strong> 
初始状态, M = 
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]

执行完操作 [2,2] 后, M = 
[[1, 1, 0],
 [1, 1, 0],
 [0, 0, 0]]

执行完操作 [3,3] 后, M = 
[[2, 2, 1],
 [2, 2, 1],
 [1, 1, 1]]

M 中最大的整数是 2, 而且 M 中有4个值为2的元素。因此返回 4。
</pre>

<p><strong>注意:</strong></p>

<ol>
	<li>m 和 n 的范围是&nbsp;[1,40000]。</li>
	<li>a 的范围是 [1,m]，b 的范围是 [1,n]。</li>
	<li>操作数目不超过 10000。</li>
</ol>
</div> 

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int row = m;
        int col = n;
        for (auto& op : ops) {
            row = min(row, op[0]);
            col = min(col, op[1]);
        }
        return row * col;
    }
};
```




