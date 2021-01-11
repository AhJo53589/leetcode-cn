# `（中等）` [1202.smallest-string-with-swaps 交换字符串中的元素](https://leetcode-cn.com/problems/smallest-string-with-swaps/)

### 题目描述
<p>给你一个字符串&nbsp;<code>s</code>，以及该字符串中的一些「索引对」数组&nbsp;<code>pairs</code>，其中&nbsp;<code>pairs[i] =&nbsp;[a, b]</code>&nbsp;表示字符串中的两个索引（编号从 0 开始）。</p>

<p>你可以 <strong>任意多次交换</strong> 在&nbsp;<code>pairs</code>&nbsp;中任意一对索引处的字符。</p>

<p>返回在经过若干次交换后，<code>s</code>&nbsp;可以变成的按字典序最小的字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入：</strong>s = "dcab", pairs = [[0,3],[1,2]]
<strong>输出：</strong>"bacd"
<strong>解释：</strong> 
交换 s[0] 和 s[3], s = "bcad"
交换 s[1] 和 s[2], s = "bacd"
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "dcab", pairs = [[0,3],[1,2],[0,2]]
<strong>输出：</strong>"abcd"
<strong>解释：</strong>
交换 s[0] 和 s[3], s = "bcad"
交换 s[0] 和 s[2], s = "acbd"
交换 s[1] 和 s[2], s = "abcd"</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "cba", pairs = [[0,1],[1,2]]
<strong>输出：</strong>"abc"
<strong>解释：</strong>
交换 s[0] 和 s[1], s = "bca"
交换 s[1] 和 s[2], s = "bac"
交换 s[0] 和 s[1], s = "abc"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
	<li><code>0 &lt;= pairs.length &lt;= 10^5</code></li>
	<li><code>0 &lt;= pairs[i][0], pairs[i][1] &lt;&nbsp;s.length</code></li>
	<li><code>s</code>&nbsp;中只含有小写英文字母</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
struct DSU {
    DSU(int n) : data(n, -1) {}

    bool unionSet(int x, int y) {
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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        DSU dsu(s.size());
        for (auto p : pairs) {
            dsu.unionSet(p[0], p[1]);
        }

        unordered_map<int, vector<char>> um;
        for (int i = 0; i < s.size(); i++) {
            um[dsu.root(i)].push_back(s[i]);
        }
        for (auto& [i, v] : um) {
            sort(v.rbegin(), v.rend());
        }

        for (int i = 0; i < s.size(); i++) {
            s[i] = um[dsu.root(i)].back();
            um[dsu.root(i)].pop_back();
        }
        return s;
    }
};
```




