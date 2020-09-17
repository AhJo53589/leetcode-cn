# `（中等）` [684.redundant-connection 冗余连接](https://leetcode-cn.com/problems/redundant-connection/)

### 题目描述
<p>在本问题中, 树指的是一个连通且无环的<strong>无向</strong>图。</p>

<p>输入一个图，该图由一个有着N个节点 (节点值不重复1, 2, ..., N) 的树及一条附加的边构成。附加的边的两个顶点包含在1到N中间，这条附加的边不属于树中已存在的边。</p>

<p>结果图是一个以<code>边</code>组成的二维数组。每一个<code>边</code>的元素是一对<code>[u, v]</code>&nbsp;，满足&nbsp;<code>u &lt; v</code>，表示连接顶点<code>u</code>&nbsp;和<code>v</code>的<strong>无向</strong>图的边。</p>

<p>返回一条可以删去的边，使得结果图是一个有着N个节点的树。如果有多个答案，则返回二维数组中最后出现的边。答案边&nbsp;<code>[u, v]</code> 应满足相同的格式&nbsp;<code>u &lt; v</code>。</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入:</strong> [[1,2], [1,3], [2,3]]
<strong>输出:</strong> [2,3]
<strong>解释:</strong> 给定的无向图为:
  1
 / \
2 - 3
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入:</strong> [[1,2], [2,3], [3,4], [1,4], [1,5]]
<strong>输出:</strong> [1,4]
<strong>解释:</strong> 给定的无向图为:
5 - 1 - 2
    |   |
    4 - 3
</pre>

<p><strong>注意:</strong></p>

<ul>
	<li>输入的二维数组大小在 3 到 1000。</li>
	<li>二维数组中的整数在1到N之间，其中N是输入数组的大小。</li>
</ul>

<p><strong>更新(2017-09-26):</strong><br>
我们已经重新检查了问题描述及测试用例，明确图是<em><strong>无向&nbsp;</strong></em>图。对于有向图详见<strong><a href="https://leetcodechina.com/problems/redundant-connection-ii/description/">冗余连接II</a>。</strong>对于造成任何不便，我们深感歉意。</p>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        data = vector<int>(edges.size() + 1, -1);
        for (auto e : edges) {
            if (root(e[0]) != -1 && root(e[0]) == root(e[1])) return e;
            join(e[0], e[1]);
        }
        return {};
    }

    bool same(int x, int y) {
        return (root(x) == root(y));
    }

    int root(int x) {
        return (data[x] < 0) ? x : data[x] = root(data[x]);
    }

    void join(int x, int y) {
        if (same(x, y)) return;
        x = root(x);
        y = root(y);
        data[x] += data[y];
        data[y] = x;  
    }

private:
    vector<int> data;
};
```




