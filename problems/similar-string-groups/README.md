# `（困难）` [839.similar-string-groups 相似字符串组](https://leetcode-cn.com/problems/similar-string-groups/)

### 题目描述
<div class="notranslate"><p>如果交换字符串&nbsp;<code>X</code> 中的两个不同位置的字母，使得它和字符串&nbsp;<code>Y</code> 相等，那么称 <code>X</code> 和 <code>Y</code> 两个字符串相似。如果这两个字符串本身是相等的，那它们也是相似的。</p>

<p>例如，<code>"tars"</code> 和 <code>"rats"</code> 是相似的 (交换 <code>0</code> 与 <code>2</code> 的位置)；&nbsp;<code>"rats"</code> 和 <code>"arts"</code> 也是相似的，但是 <code>"star"</code> 不与 <code>"tars"</code>，<code>"rats"</code>，或 <code>"arts"</code> 相似。</p>

<p>总之，它们通过相似性形成了两个关联组：<code>{"tars", "rats", "arts"}</code> 和 <code>{"star"}</code>。注意，<code>"tars"</code> 和 <code>"arts"</code> 是在同一组中，即使它们并不相似。形式上，对每个组而言，要确定一个单词在组中，只需要这个词和该组中至少一个单词相似。</p>

<p>给你一个字符串列表 <code>strs</code>。列表中的每个字符串都是 <code>strs</code> 中其它所有字符串的一个字母异位词。请问 <code>strs</code> 中有多少个相似字符串组？</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>strs = ["tars","rats","arts","star"]
<strong>输出：</strong>2
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>strs = ["omv","ovm"]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= strs.length &lt;= 100</code></li>
	<li><code>1 &lt;= strs[i].length &lt;= 1000</code></li>
	<li><code>sum(strs[i].length) &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>strs[i]</code> 只包含小写字母。</li>
	<li><code>strs</code> 中的所有单词都具有相同的长度，且是彼此的字母异位词。</li>
</ul>

<p>&nbsp;</p>

<p><strong>备注：</strong></p>

<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 字母异位词（anagram），一种把某个字符串的字母的位置（顺序）加以改换所形成的新词。</p>
</div>

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/similar-string-groups/solution/similar-string-groups-by-ikaruga-9y7t/)

### 答题
``` C++
struct DSU {
    DSU(int n) : data(n, -1), cnt(n) {}

    bool unionSet(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (data[x] > data[y]) {
            swap(x, y);
        }
        data[x] += data[y];
        data[y] = x;
        cnt--;
        return true;
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }

    int size(int x) {
        return -data[root(x)];
    }

    vector<int> data;
    int cnt = 0;
};

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        DSU dsu(strs.size());
        for (int i = 0; i < strs.size(); i++) {
            for (int j = i + 1; j < strs.size(); j++) {
                if (dsu.same(i, j)) continue;
                if (!check(strs[i], strs[j])) continue;
                dsu.unionSet(i, j);
            }
        }
        return dsu.cnt;
    }

    bool check(string& s1, string& s2) {
        int dif = 0;
        for (int i = 0; i < s1.size(); i++) {
            dif += (s1[i] != s2[i]);
        }
        return (dif == 0 || dif == 2);
    }
};
```




