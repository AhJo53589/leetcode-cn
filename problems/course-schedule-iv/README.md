# `（中等）` [1462.course-schedule-iv 课程安排 IV](https://leetcode-cn.com/problems/course-schedule-iv/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-27/problems/course-schedule-iv/)

### 题目描述
<p>你总共需要上 <code>n</code>&nbsp;门课，课程编号依次为 <code>0</code>&nbsp;到 <code>n-1</code>&nbsp;。</p>

<p>有的课会有直接的先修课程，比如如果想上课程&nbsp;0 ，你必须先上课程 1 ，那么会以 <code>[1,0]</code>&nbsp;数对的形式给出先修课程数对。</p>

<p>给你课程总数 <code>n</code>&nbsp;和一个直接先修课程数对列表&nbsp;<code>prerequisite</code> 和一个查询对列表&nbsp;<code>queries</code>&nbsp;。</p>

<p>对于每个查询对 <code>queries[i]</code>&nbsp;，请判断&nbsp;<code>queries[i][0]</code>&nbsp;是否是&nbsp;<code>queries[i][1]</code>&nbsp;的先修课程。</p>

<p>请返回一个布尔值列表，列表中每个元素依次分别对应 <code>queries</code>&nbsp;每个查询对的判断结果。</p>

<p><strong>注意：</strong>如果课程&nbsp;<strong>a</strong>&nbsp;是课程&nbsp;<strong>b</strong>&nbsp;的先修课程且课程&nbsp;<strong>b</strong>&nbsp;是课程&nbsp;<strong>c</strong>&nbsp;的先修课程，那么课程&nbsp;<strong>a</strong>&nbsp;也是课程&nbsp;<strong>c</strong>&nbsp;的先修课程。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img style="height: 300px; width: 300px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/05/30/graph.png" alt=""></p>

<pre><strong>输入：</strong>n = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
<strong>输出：</strong>[false,true]
<strong>解释：</strong>课程 0 不是课程 1 的先修课程，但课程 1 是课程 0 的先修课程。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 2, prerequisites = [], queries = [[1,0],[0,1]]
<strong>输出：</strong>[false,false]
<strong>解释：</strong>没有先修课程对，所以每门课程之间是独立的。
</pre>

<p><strong>示例 3：</strong></p>

<p><img style="height: 300px; width: 300px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/05/30/graph-1.png" alt=""></p>

<pre><strong>输入：</strong>n = 3, prerequisites = [[1,2],[1,0],[2,0]], queries = [[1,0],[1,2]]
<strong>输出：</strong>[true,true]
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>n = 3, prerequisites = [[1,0],[2,0]], queries = [[0,1],[2,0]]
<strong>输出：</strong>[false,true]
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>n = 5, prerequisites = [[0,1],[1,2],[2,3],[3,4]], queries = [[0,4],[4,0],[1,3],[3,0]]
<strong>输出：</strong>[true,false,true,false]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= n <= 100</code></li>
	<li><code>0 <= prerequisite.length <= (n * (n - 1) / 2)</code></li>
	<li><code>0 <= prerequisite[i][0], prerequisite[i][1] < n</code></li>
	<li><code>prerequisite[i][0] != prerequisite[i][1]</code></li>
	<li>先修课程图中没有环。</li>
	<li>先修课程图中没有重复的边。</li>
	<li><code>1 <= queries.length <= 10^4</code></li>
	<li><code>queries[i][0] != queries[i][1]</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/course-schedule-iv/solution/course-schedule-iv-by-ikaruga/)

### 答题
``` C++
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> inDegree(n, 0);
        vector<vector<int>> lst(n, vector<int>());
        vector<unordered_set<int>> vi(n, unordered_set<int>());
        
        for (auto v : prerequisites) {
            inDegree[v[1]]++;
            lst[v[0]].push_back(v[1]);
        }

        queue<int> que;
        for (auto i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] == 0) {
                que.push(i);
            }
        }

        while (!que.empty()) {
            auto q = que.front();
            que.pop();

            for (auto l : lst[q]) {
                for (auto v = vi[q].begin(); v != vi[q].end(); v++) {
                    vi[l].insert(*v);
                }
                vi[l].insert(q);

                if (--inDegree[l] == 0) {
                    que.push(l);
                }
            }
        }

        vector<bool> ans(queries.size(), false);
        for (int i = 0; i < queries.size(); i++) {
            ans[i] = (vi[queries[i][1]].count(queries[i][0]) != 0);
        }

        return ans;
    }
```




