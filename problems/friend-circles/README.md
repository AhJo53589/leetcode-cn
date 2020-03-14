# `（中等）` [547.friend-circles 朋友圈](https://leetcode-cn.com/problems/friend-circles/)

### 题目描述
<p>班上有&nbsp;<strong>N&nbsp;</strong>名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。如果已知 A 是 B&nbsp;的朋友，B 是 C&nbsp;的朋友，那么我们可以认为 A 也是 C&nbsp;的朋友。所谓的朋友圈，是指所有朋友的集合。</p>

<p>给定一个&nbsp;<strong>N * N&nbsp;</strong>的矩阵&nbsp;<strong>M</strong>，表示班级中学生之间的朋友关系。如果M[i][j] = 1，表示已知第 i 个和 j 个学生<strong>互为</strong>朋友关系，否则为不知道。你必须输出所有学生中的已知的朋友圈总数。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
<strong>输出:</strong> 2 
<strong>说明：</strong>已知学生0和学生1互为朋友，他们在一个朋友圈。
第2个学生自己在一个朋友圈。所以返回2。
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
<strong>输出:</strong> 1
<strong>说明：</strong>已知学生0和学生1互为朋友，学生1和学生2互为朋友，所以学生0和学生2也是朋友，所以他们三个在一个朋友圈，返回1。
</pre>

<p><strong>注意：</strong></p>

<ol>
	<li>N 在[1,200]的范围内。</li>
	<li>对于所有学生，有M[i][i] = 1。</li>
	<li>如果有M[i][j] = 1，则有M[j][i] = 1。</li>
</ol>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/friend-circles/solution/547-by-ikaruga/)

### 答题
``` C++
struct DSU
{
    DSU(int n) : data(n, -1) { }

    bool unionSet(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x == y) return false;

        if (data[y] < data[x]) std::swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    bool same(int x, int y) { return root(x) == root(y); }

    int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }

    int size(int x) { return -data[root(x)]; }

    std::vector<int> data;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) 
    {
        int ans = M.size();
        DSU dsu(M.size());
        for (size_t i = 0; i < M.size(); i++)
        {
            for (size_t j = i + 1; j < M.size(); j++)
            {
                if (M[i][j] == 0) continue;
                ans -= dsu.unionSet(i, j);
            }
        }
        return ans;
    }
};
```




