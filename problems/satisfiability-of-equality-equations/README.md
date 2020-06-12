# `（中等）` [990.satisfiability-of-equality-equations 等式方程的可满足性](https://leetcode-cn.com/problems/satisfiability-of-equality-equations/)

### 题目描述
<p>给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 <code>equations[i]</code> 的长度为 <code>4</code>，并采用两种不同的形式之一：<code>"a==b"</code> 或&nbsp;<code>"a!=b"</code>。在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。</p>

<p>只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回&nbsp;<code>true</code>，否则返回 <code>false</code>。&nbsp;</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>["a==b","b!=a"]
<strong>输出：</strong>false
<strong>解释：</strong>如果我们指定，a = 1 且 b = 1，那么可以满足第一个方程，但无法满足第二个方程。没有办法分配变量同时满足这两个方程。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>["b==a","a==b"]
<strong>输出：</strong>true
<strong>解释：</strong>我们可以指定 a = 1 且 b = 1 以满足满足这两个方程。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>["a==b","b==c","a==c"]
<strong>输出：</strong>true
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>["a==b","b!=c","c==a"]
<strong>输出：</strong>false
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>["c==c","b==d","x!=z"]
<strong>输出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 <= equations.length <= 500</code></li>
	<li><code>equations[i].length == 4</code></li>
	<li><code>equations[i][0]</code> 和&nbsp;<code>equations[i][3]</code>&nbsp;是小写字母</li>
	<li><code>equations[i][1]</code> 要么是&nbsp;<code>'='</code>，要么是&nbsp;<code>'!'</code></li>
	<li><code>equations[i][2]</code>&nbsp;是&nbsp;<code>'='</code></li>
</ol>


---
### 思路
```
```



### 答题
``` C++
struct DSU
{
    std::vector<int> data;
    
    void init(int n) { data.assign(n, -1); }
    
    bool unionSet(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x != y)
        {
            if (data[y] < data[x])
            {
                std::swap(x, y);
            }
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }

    bool same(int x, int y) { return root(x) == root(y); }

    int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }

    int size(int x) { return -data[root(x)]; }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU dsu;
        dsu.init(26);

        for (auto& e : equations) {
            if (e[1] == '!') continue;
            dsu.unionSet((int)(e[0] - 'a'), (int)(e[3] - 'a'));
        }

        for (auto& e : equations) {
            if (e[1] != '!') continue;
            if (dsu.same(e[0] - 'a', e[3] - 'a')) return false;
        }

        return true;
    }
};
```




