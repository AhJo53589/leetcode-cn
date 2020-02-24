# `（中等）` [1353.maximum-number-of-events-that-can-be-attended 最多可以参加的会议数目](https://leetcode-cn.com/problems/maximum-number-of-events-that-can-be-attended/)

[contest](https://leetcode-cn.com/contest/weekly-contest-176/problems/maximum-number-of-events-that-can-be-attended/)

### 题目描述
<p>给你一个数组&nbsp;<code>events</code>，其中&nbsp;<code>events[i] = [startDay<sub>i</sub>, endDay<sub>i</sub>]</code>&nbsp;，表示会议&nbsp;<code>i</code>&nbsp;开始于&nbsp;<code>startDay<sub>i</sub></code>&nbsp;，结束于&nbsp;<code>endDay<sub>i</sub></code>&nbsp;。</p>
<p>你可以在满足&nbsp;<code>startDay<sub>i</sub>&nbsp;&lt;= d &lt;= endDay<sub>i</sub></code><sub>&nbsp;</sub>中的任意一天&nbsp;<code>d</code>&nbsp;参加会议&nbsp;<code>i</code>&nbsp;。注意，一天只能参加一个会议。</p>
<p>请你返回你可以参加的&nbsp;<strong>最大&nbsp;</strong>会议数目。</p>
<p>&nbsp;</p>
<p><strong>示例 1：</strong></p>
<p><img alt="" src="./e1.png" style="height: 400px; width: 600px;"></p>
<pre><strong>输入：</strong>events = [[1,2],[2,3],[3,4]]
<strong>输出：</strong>3
<strong>解释：</strong>你可以参加所有的三个会议。
安排会议的一种方案如上图。
第 1 天参加第一个会议。
第 2 天参加第二个会议。
第 3 天参加第三个会议。
</pre>

<p><strong>示例 2：</strong></p>
<pre><strong>输入：</strong>events= [[1,2],[2,3],[3,4],[1,2]]
<strong>输出：</strong>4
</pre>

<p><strong>示例 3：</strong></p>
<pre><strong>输入：</strong>events = [[1,4],[4,4],[2,2],[3,4],[1,1]]
<strong>输出：</strong>4
</pre>

<p><strong>示例 4：</strong></p>
<pre><strong>输入：</strong>events = [[1,100000]]
<strong>输出：</strong>1
</pre>

<p><strong>示例 5：</strong></p>
<pre><strong>输入：</strong>events = [[1,1],[1,2],[1,3],[1,4],[1,5],[1,6],[1,7]]
<strong>输出：</strong>7
</pre>

<p>&nbsp;</p>
<p><strong>提示：</strong></p>
<ul>
	<li><code>1 &lt;= events.length &lt;= 10^5</code></li>
	<li><code>events[i].length == 2</code></li>
	<li><code>1 &lt;= events[i][0] &lt;= events[i][1] &lt;= 10^5</code></li>
</ul>

​            

---
### 思路
```

```

[发布的题解](https://leetcode-cn.com/problems/maximum-number-of-events-that-can-be-attended/solution/5342-by-ikaruga/)

### 答题
``` C++
int maxEvents(vector<vector<int>>& events) 
{
    sort(events.rbegin(), events.rend());

    auto f = [](const vector<int>& a, const vector<int>& b)
    {
        return a[1] > b[1];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(f)> pq(f);

    int ans = 0;
    int day = 0;
    while (!events.empty() || !pq.empty())
    {
        day++;
        while (!pq.empty() && pq.top()[1] < day)
        {
            pq.pop();
        }
        while (!events.empty() && events.back()[0] == day)
        {
            pq.push(events.back());
            events.pop_back();
        }
        if (pq.empty()) continue;
        pq.pop();
        ans++;
    }

    return ans;
}
```




