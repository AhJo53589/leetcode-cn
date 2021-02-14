# `（困难）` [5679.minimum-degree-of-a-connected-trio-in-a-graph 一个图中连通三元组的最小度数](https://leetcode-cn.com/problems/minimum-degree-of-a-connected-trio-in-a-graph/)

[contest](https://leetcode-cn.com/contest/weekly-contest-228/problems/minimum-degree-of-a-connected-trio-in-a-graph/)

### 题目描述
<div class="notranslate"><p>给你一个无向图，整数 <code>n</code>&nbsp;表示图中节点的数目，<code>edges</code>&nbsp;数组表示图中的边，其中&nbsp;<code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>]</code>&nbsp;，表示&nbsp;<code>u<sub>i</sub></code> 和&nbsp;<code>v<sub>i</sub></code><sub>&nbsp;</sub>之间有一条无向边。</p>

<p>一个 <strong>连通三元组</strong>&nbsp;指的是 <strong>三个</strong>&nbsp;节点组成的集合且这三个点之间 <strong>两两</strong>&nbsp;有边。</p>

<p><strong>连通三元组的度数</strong>&nbsp;是所有满足此条件的边的数目：一个顶点在三元组内，而另一个顶点不在三元组内。</p>

<p>请你返回所有连通三元组中度数的 <strong>最小值</strong>&nbsp;，如果图中没有连通三元组，那么返回 <code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img style="width: 388px; height: 164px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/02/14/trios1.png" alt="">
<pre><b>输入：</b>n = 6, edges = [[1,2],[1,3],[3,2],[4,1],[5,2],[3,6]]
<b>输出：</b>3
<b>解释：</b>只有一个三元组 [1,2,3] 。构成度数的边在上图中已被加粗。
</pre>

<p><strong>示例 2：</strong></p>
<img style="width: 388px; height: 164px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/02/14/trios2.png" alt="">
<pre><b>输入：</b>n = 7, edges = [[1,3],[4,1],[4,3],[2,5],[5,6],[6,7],[7,5],[2,6]]
<b>输出：</b>0
<b>解释：</b>有 3 个三元组：
1) [1,4,3]，度数为 0 。
2) [2,5,6]，度数为 2 。
3) [5,6,7]，度数为 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 400</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>1 &lt;= edges.length &lt;= n * (n-1) / 2</code></li>
	<li><code>1 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt;= n</code></li>
	<li><code>u<sub>i </sub>!= v<sub>i</sub></code></li>
	<li>图中没有重复的边。</li>
</ul>
</div>

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        int ans = INT_MAX;

        vector<vector<bool>> vi(n + 1, vector<bool>(n + 1, false));
        vector<int> cnt(n + 1, 0);
        for (auto& e : edges) {
            vi[e[0]][e[1]] = true;
            vi[e[1]][e[0]] = true;
            cnt[e[0]]++;
            cnt[e[1]]++;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (!vi[i][j]) continue;
                for (int k = j + 1; k <= n; k++) {
                    ans = (vi[i][k] && vi[j][k]) ? min(ans, cnt[i] + cnt[j] + cnt[k] - 6) : ans;
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
```




