# `（困难）` [5970.maximum-employees-to-be-invited-to-a-meeting 参加会议的最多员工数](https://leetcode-cn.com/problems/maximum-employees-to-be-invited-to-a-meeting/)

[contest](https://leetcode-cn.com/contest/weekly-contest-274/problems/maximum-employees-to-be-invited-to-a-meeting/)

### 题目描述
<div class="notranslate"><p>一个公司准备组织一场会议，邀请名单上有&nbsp;<code>n</code>&nbsp;位员工。公司准备了一张 <strong>圆形</strong>&nbsp;的桌子，可以坐下 <strong>任意数目</strong>&nbsp;的员工。</p>

<p>员工编号为 <code>0</code>&nbsp;到 <code>n - 1</code>&nbsp;。每位员工都有一位 <strong>喜欢</strong>&nbsp;的员工，每位员工&nbsp;<strong>当且仅当</strong>&nbsp;他被安排在喜欢员工的旁边，他才会参加会议。每位员工喜欢的员工 <strong>不会</strong>&nbsp;是他自己。</p>

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>favorite</code>&nbsp;，其中&nbsp;<code>favorite[i]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;位员工喜欢的员工。请你返回参加会议的&nbsp;<strong>最多员工数目</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img style="width: 236px; height: 195px;" src="https://assets.leetcode.com/uploads/2021/12/14/ex1.png" alt=""></p>

<pre><b>输入：</b>favorite = [2,2,1,2]
<b>输出：</b>3
<strong>解释：</strong>
上图展示了公司邀请员工 0，1 和 2 参加会议以及他们在圆桌上的座位。
没办法邀请所有员工参与会议，因为员工 2 没办法同时坐在 0，1 和 3 员工的旁边。
注意，公司也可以邀请员工 1，2 和 3 参加会议。
所以最多参加会议的员工数目为 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>favorite = [1,2,0]
<b>输出：</b>3
<b>解释：</b>
每个员工都至少是另一个员工喜欢的员工。所以公司邀请他们所有人参加会议的前提是所有人都参加了会议。
座位安排同图 1 所示：
- 员工 0 坐在员工 2 和 1 之间。
- 员工 1 坐在员工 0 和 2 之间。
- 员工 2 坐在员工 1 和 0 之间。
参与会议的最多员工数目为 3 。
</pre>

<p><strong>示例 3：</strong></p>

<p><img style="width: 219px; height: 220px;" src="https://assets.leetcode.com/uploads/2021/12/14/ex2.png" alt=""></p>

<pre><b>输入：</b>favorite = [3,0,1,4,1]
<b>输出：</b>4
<b>解释：</b>
上图展示了公司可以邀请员工 0，1，3 和 4 参加会议以及他们在圆桌上的座位。
员工 2 无法参加，因为他喜欢的员工 0 旁边的座位已经被占领了。
所以公司只能不邀请员工 2 。
参加会议的最多员工数目为 4 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == favorite.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= favorite[i] &lt;=&nbsp;n - 1</code></li>
	<li><code>favorite[i] != i</code></li>
</ul>
</div>

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/maximum-employees-to-be-invited-to-a-meeting/solution/maximum-employees-to-be-invited-to-a-mee-8pwb/)

### 答题
``` C++
class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int ans = 0;

        unordered_map<int, vector<int>> uf;
        unordered_map<int, int> vi;
        vector<int> endPoint;
        for (int i = 0; i < favorite.size(); i++) {
            if (favorite[favorite[i]] == i) {
                endPoint.push_back(i);
            }
            else {
                uf[favorite[i]].push_back(i);
            }
        }

        for (int i = 0; i < endPoint.size(); i++) {
            ans += dfs(endPoint[i], uf, vi);
        }

        for (int i = 0; i < favorite.size(); i++) {
            if (vi[i] == -1) continue;
            ans = max(ans, circle(i, favorite, vi));
        }
        return ans;
    }

    int dfs(int cur, unordered_map<int, vector<int>>& uf, unordered_map<int, int>& vi) {
        int cnt = 0;
        for (int i = 0; i < uf[cur].size(); i++) {
            cnt = max(cnt, dfs(uf[cur][i], uf, vi));
        }
        vi[cur] = -1;
        return cnt + 1;
    }

    int circle(int idx_in, vector<int>& favorite, unordered_map<int, int>& vi) {
        int cnt = 0;
        int cur = idx_in;
        int step = 0;
        int flag = -2;
        while (flag == -2) {
            vi[cur] = ++step;
            int next = favorite[cur];
            flag = (vi[next] == -1) ? -1 : flag;
            flag = (vi[next] > 0) ? next : flag;
            cur = next;
        }

        if (flag != -1) {
            cnt = step - vi[flag] + 1;
        }

        cur = idx_in;
        while (vi[cur] != -1) {
            vi[cur] = -1;
            cur = favorite[cur];
        }

        return cnt;
    }
};
```




