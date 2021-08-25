# `（中等）` [797.all-paths-from-source-to-target 所有可能的路径](https://leetcode-cn.com/problems/all-paths-from-source-to-target/)

### 题目描述
<p>给你一个有&nbsp;<code>n</code>&nbsp;个节点的 <strong>有向无环图（DAG）</strong>，请你找出所有从节点 <code>0</code>&nbsp;到节点 <code>n-1</code>&nbsp;的路径并输出（<strong>不要求按特定顺序</strong>）</p>

<p>二维数组的第 <code>i</code> 个数组中的单元都表示有向图中 <code>i</code> 号节点所能到达的下一些节点，空就是没有下一个结点了。</p>

<p>译者注：有向图是有方向的，即规定了 a→b 你就不能从 b→a 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img style="height: 242px; width: 242px;" src="https://assets.leetcode.com/uploads/2020/09/28/all_1.jpg" alt=""></p>

<pre><strong>输入：</strong>graph = [[1,2],[3],[3],[]]
<strong>输出：</strong>[[0,1,3],[0,2,3]]
<strong>解释：</strong>有两条路径 0 -&gt; 1 -&gt; 3 和 0 -&gt; 2 -&gt; 3
</pre>

<p><strong>示例 2：</strong></p>

<p><img style="height: 301px; width: 423px;" src="https://assets.leetcode.com/uploads/2020/09/28/all_2.jpg" alt=""></p>

<pre><strong>输入：</strong>graph = [[4,3,1],[3,2,4],[3],[4],[]]
<strong>输出：</strong>[[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>graph = [[1],[]]
<strong>输出：</strong>[[0,1]]
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>graph = [[1,2,3],[2],[3],[]]
<strong>输出：</strong>[[0,1,2,3],[0,2,3],[0,3]]
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>graph = [[1,3],[2],[3],[]]
<strong>输出：</strong>[[0,1,2,3],[0,3]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == graph.length</code></li>
	<li><code>2 &lt;= n &lt;= 15</code></li>
	<li><code>0 &lt;= graph[i][j] &lt; n</code></li>
	<li><code>graph[i][j] != i</code>（即，不存在自环）</li>
	<li><code>graph[i]</code> 中的所有元素 <strong>互不相同</strong></li>
	<li>保证输入为 <strong>有向无环图（DAG）</strong></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/all-paths-from-source-to-target/solution/all-paths-from-source-to-target-by-ikaru-fsac/)

### 答题
``` C++
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path = {0};
        dfs(graph, path, 0);
        return ans;
    }

    void dfs(vector<vector<int>>& graph, vector<int>& path, int cur) {
        if (cur == (int)graph.size() - 1) {
            ans.push_back(path);
            return;
        }

        for (auto& next : graph[cur]) {
            path.push_back(next);
            dfs(graph, path, next);
            path.pop_back();
        }
    }

private:
    vector<vector<int>> ans;
};
```




