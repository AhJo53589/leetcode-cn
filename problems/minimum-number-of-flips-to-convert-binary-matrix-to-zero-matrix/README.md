# `（困难）` [5282.minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix 转化为全零矩阵的最少反转次数](https://leetcode-cn.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/)

[contest](https://leetcode-cn.com/contest/weekly-contest-166/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/)

### 题目描述
<p>给你一个&nbsp;<code>m x n</code>&nbsp;的二进制矩阵&nbsp;<code>mat</code>。</p>

<p>每一步，你可以选择一个单元格并将它反转（反转表示 0 变 1 ，1 变 0 ）。如果存在和它相邻的单元格，那么这些相邻的单元格也会被反转。（注：相邻的两个单元格共享同一条边。）</p>

<p>请你返回将矩阵&nbsp;<code>mat</code> 转化为全零矩阵的<em>最少反转次数</em>，如果无法转化为全零矩阵，请返回&nbsp;<strong>-1</strong>&nbsp;。</p>

<p>二进制矩阵的每一个格子要么是 0 要么是 1 。</p>

<p>全零矩阵是所有格子都为 0 的矩阵。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<p><img style="height:86px; width:409px" src="https://assets.leetcode.com/uploads/2019/11/28/matrix.png" alt=""></p>

<pre><strong>输入：</strong>mat = [[0,0],[0,1]]
<strong>输出：</strong>3
<strong>解释：</strong>一个可能的解是反转 (1, 0)，然后 (0, 1) ，最后是 (1, 1) 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>mat = [[0]]
<strong>输出：</strong>0
<strong>解释：</strong>给出的矩阵是全零矩阵，所以你不需要改变它。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>mat = [[1,1,1],[1,0,1],[0,0,0]]
<strong>输出：</strong>6
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>mat = [[1,0,0],[1,0,0]]
<strong>输出：</strong>-1
<strong>解释：</strong>该矩阵无法转变成全零矩阵
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m ==&nbsp;mat.length</code></li>
	<li><code>n ==&nbsp;mat[0].length</code></li>
	<li><code>1 &lt;= m&nbsp;&lt;= 3</code></li>
	<li><code>1 &lt;= n&nbsp;&lt;= 3</code></li>
	<li><code>mat[i][j]</code>&nbsp;是 0 或 1 。</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
vector<vector<int>> turn(vector<vector<int>> m, size_t x, size_t y)
{
    m[x][y] = m[x][y] == 0 ? 1 : 0;
    if (x + 1 < m.size())
    {
        m[x + 1][y] = m[x + 1][y] == 0 ? 1 : 0;
    }
    if (x - 1 < m.size())
    {
        m[x - 1][y] = m[x - 1][y] == 0 ? 1 : 0;
    }
    if (y + 1 < m[0].size())
    {
        m[x][y + 1] = m[x][y + 1] == 0 ? 1 : 0;
    }
    if (y - 1 < m[0].size())
    {
        m[x][y - 1] = m[x][y - 1] == 0 ? 1 : 0;
    }
    return m;
}

bool check(vector<vector<int>>& m)
{
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[0].size(); j++)
        {
            if (m[i][j] == 1) return false;
        }
    }
    return true;
}

int minFlips(vector<vector<int>>& mat)
{
    if (check(mat)) return 0;
    set<vector<vector<int>>> s;
    queue<vector<vector<int>>> que;
    s.insert(mat);
    que.push(mat);

    int ans = 0;
    while (ans < 100)
    {
        ans++;
        queue<vector<vector<int>>> que2;
        while(!que.empty())
        {
            vector<vector<int>> m = que.front();
            que.pop();
            for (int i = 0; i < m.size(); i++)
            {
                for (int j = 0; j < m[0].size(); j++)
                {
                    vector<vector<int>> m2 = turn(m, i, j);
                    if (s.count(m2) != 0) continue;
                    s.insert(m2);
                    if (check(m2)) return ans;
                    que2.push(m2);
                }
            }
        }   
        swap(que, que2);
    }
    ans = (ans == 100) ? -1 : ans;
    return ans;
}
```




