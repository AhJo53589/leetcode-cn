# `（中等）` [1519.number-of-nodes-in-the-sub-tree-with-the-same-label 子树中标签相同的节点数](https://leetcode-cn.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/)

[contest](https://leetcode-cn.com/contest/weekly-contest-198/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/)

### 题目描述
<p>给你一棵树（即，一个连通的无环无向图），这棵树由编号从 <code>0</code>&nbsp; 到 <code>n - 1</code> 的 n 个节点组成，且恰好有 <code>n - 1</code> 条 <code>edges</code> 。树的根节点为节点 <code>0</code> ，树上的每一个节点都有一个标签，也就是字符串 <code>labels</code> 中的一个小写字符（编号为 <code>i</code> 的 节点的标签就是 <code>labels[i]</code> ）</p>

<p>边数组 <code>edges</code> 以 <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> 的形式给出，该格式表示节点 <code>a<sub>i</sub></code> 和 <code>b<sub>i</sub></code> 之间存在一条边。</p>

<p>返回一个大小为 <em><code>n</code></em> 的数组，其中 <code>ans[i]</code> 表示第 <code>i</code> 个节点的子树中与节点 <code>i</code> 标签相同的节点数。</p>

<p>树 <code>T</code> 中的子树是由 <code>T</code> 中的某个节点及其所有后代节点组成的树。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img style="height: 321px; width: 441px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/07/19/q3e1.jpg" alt=""></p>

<pre><strong>输入：</strong>n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], labels = "abaedcd"
<strong>输出：</strong>[2,1,1,1,1,1,1]
<strong>解释：</strong>节点 0 的标签为 'a' ，以 'a' 为根节点的子树中，节点 2 的标签也是 'a' ，因此答案为 2 。注意树中的每个节点都是这棵子树的一部分。
节点 1 的标签为 'b' ，节点 1 的子树包含节点 1、4 和 5，但是节点 4、5 的标签与节点 1 不同，故而答案为 1（即，该节点本身）。
</pre>

<p><strong>示例 2：</strong></p>

<p><img style="height: 321px; width: 381px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/07/19/q3e2.jpg" alt=""></p>

<pre><strong>输入：</strong>n = 4, edges = [[0,1],[1,2],[0,3]], labels = "bbbb"
<strong>输出：</strong>[4,2,1,1]
<strong>解释：</strong>节点 2 的子树中只有节点 2 ，所以答案为 1 。
节点 3 的子树中只有节点 3 ，所以答案为 1 。
节点 1 的子树中包含节点 1 和 2 ，标签都是 'b' ，因此答案为 2 。
节点 0 的子树中包含节点 0、1、2 和 3，标签都是 'b'，因此答案为 4 。
</pre>

<p><strong>示例 3：</strong></p>

<p><img style="height: 321px; width: 381px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/07/19/q3e3.jpg" alt=""></p>

<pre><strong>输入：</strong>n = 5, edges = [[0,1],[0,2],[1,3],[0,4]], labels = "aabab"
<strong>输出：</strong>[3,2,1,1,1]
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>n = 6, edges = [[0,1],[0,2],[1,3],[3,4],[4,5]], labels = "cbabaa"
<strong>输出：</strong>[1,2,1,1,2,1]
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>n = 7, edges = [[0,1],[1,2],[2,3],[3,4],[4,5],[5,6]], labels = "aaabaaa"
<strong>输出：</strong>[6,5,4,1,3,2,1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 10^5</code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 <= a<sub>i</sub>,&nbsp;b<sub>i</sub> < n</code></li>
	<li><code>a<sub>i</sub> !=&nbsp;b<sub>i</sub></code></li>
	<li><code>labels.length == n</code></li>
	<li><code>labels</code> 仅由小写英文字母组成</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/solution/same-label-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> ans(n, 0);
        vector<vector<int>> path(n);
        vi = vector<bool>(n, false);
        for (int i = 0; i < edges.size(); i++) {
            path[edges[i][0]].push_back(edges[i][1]);
            path[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(path, labels, 0, ans);
        return ans;
    }

    vector<int> dfs(vector<vector<int>>& path, string& labels, int idx, vector<int>& ans) {
        vi[idx] = true;
        vector<int> cnt(26, 0);
        cnt[labels[idx] - 'a']++;

        for (auto i : path[idx]) {
            if (vi[i]) continue;
            auto t = dfs(path, labels, i, ans);
            for (int j = 0; j < cnt.size(); j++) {
                cnt[j] += t[j];
            }
        }
        ans[idx] = cnt[labels[idx] - 'a'];
        return cnt;
    }

private:
    vector<bool> vi;
};
```




